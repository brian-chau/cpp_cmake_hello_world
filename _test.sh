#!/bin/bash

# This should match the project name in the CMakeLists.txt file in the line "project(exe_test DESCRIPTION "Hello world" LANGUAGES CXX)"
test_exe_name="exe_test"
rm -rf build bin/$test_exe_name

echo Preparing to test...
# RunningSum
# mkdir build && cd build && cmake -Dtest=ON -DRunningSum=ON  .. >/dev/null 2>&1 && make >/dev/null 2>&1

# Pivot
# mkdir build && cd build && cmake -Dtest=ON -DPivot=ON       .. >/dev/null 2>&1 && make >/dev/null 2>&1

# HappyNumber
# mkdir build && cd build && cmake -Dtest=ON -DHappyNumber=ON .. >/dev/null 2>&1 && make >/dev/null 2>&1

# Run every test
mkdir build && cd build && cmake -Dtest=ON                 .. >/dev/null 2>&1 && make >/dev/null 2>&1

echo Testing...
make test > ../TestResults/gtest_results.txt
tests_failed=$(grep "The following tests FAILED:" ../TestResults/gtest_results.txt | wc -l)
if [[ $tests_failed -ge 1 ]]; then
    echo Tests failed!
    cat ../TestResults/gtest_results.txt
    exit 1
fi
echo Tests passed!

# Generate code coverage
echo Generating code coverage...
lcov --capture --directory ./CMakeFiles/$test_exe_name.dir/sources --output-file ../TestResults/main_coverage.info >/dev/null 2>&1
lcov --remove ../TestResults/main_coverage.info -o ../TestResults/main_filtered.info '/usr/include/*' '/usr/include/x86_64-linux-gnu/*' '/usr/lib/*' '/usr/local/*' '/11/*' >/dev/null 2>&1
genhtml ../TestResults/main_filtered.info --output-directory ../TestResults/CodeCoverage > ../TestResults/lcov_results.txt
mv ./Testing/Temporary/LastTest.log ../TestResults/LastTest.log

# Fetch code coverage for README badges
echo Generating code coverage badges...
string_line_code_coverage=$(grep -oP "(?<=lines\.\.\.\.\.\.: )\S+(?=\% \(\d+ of \d+ lines\))" ../TestResults/lcov_results.txt)
string_fxn_code_coverage=$(grep -oP "(?<=functions\.\.: )\S+(?=\% \(\d+ of \d+ functions\))" ../TestResults/lcov_results.txt)
int_line_code_coverage=$(printf '%.0f\n' $string_line_code_coverage)
int_fxn_code_coverage=$(printf '%.0f\n' $string_fxn_code_coverage)

# Test results badge
if $test_failed; then
    cp ../TestResults/Badges/Test_Results/Passed/green.svg ../TestResults/_PassFailBadge.svg
else
    cp ../TestResults/Badges/Test_Results/Failed/red.svg ../TestResults/_PassFailBadge.svg
fi

# Fxn Code Coverage badge
if [[ $int_fxn_code_coverage -ge 90 ]] ; then
    cp ../TestResults/Badges/Code_Coverage/green/"${int_fxn_code_coverage}_Percent.svg"  ../TestResults/_FxnCodeCoverageBadge.svg
elif [[ $int_fxn_code_coverage -ge 75 ]] ; then
    cp ../TestResults/Badges/Code_Coverage/yellow/"${int_fxn_code_coverage}_Percent.svg" ../TestResults/_FxnCodeCoverageBadge.svg
else
    cp ../TestResults/Badges/Code_Coverage/red/"${int_fxn_code_coverage}_Percent.svg"    ../TestResults/_FxnCodeCoverageBadge.svg
fi

# Line Code Coverage badge
if [[ $int_line_code_coverage -ge 90 ]] ; then
    cp ../TestResults/Badges/Code_Coverage/green/"${int_line_code_coverage}_Percent.svg"  ../TestResults/_LineCodeCoverageBadge.svg
elif [[ $int_line_code_coverage -ge 75 ]] ; then
    cp ../TestResults/Badges/Code_Coverage/yellow/"${int_line_code_coverage}_Percent.svg" ../TestResults/_LineCodeCoverageBadge.svg
else
    cp ../TestResults/Badges/Code_Coverage/red/"${int_line_code_coverage}_Percent.svg"    ../TestResults/_LineCodeCoverageBadge.svg
fi

echo Cleaning up...
# Clean up
rm -rf ../build

echo Done!

