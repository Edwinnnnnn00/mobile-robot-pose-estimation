# CMake generated Testfile for 
# Source directory: /home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue
# Build directory: /home/edwinooi/Desktop/foxy_ws/build/costmap_queue
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(mbq_test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/mbq_test.gtest.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_cmake_gtest/mbq_test.txt" "--command" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/mbq_test" "--gtest_output=xml:/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/mbq_test.gtest.xml")
set_tests_properties(mbq_test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/mbq_test" TIMEOUT "60" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;37;ament_add_gtest;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
add_test(utest "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/utest.gtest.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_cmake_gtest/utest.txt" "--command" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/utest" "--gtest_output=xml:/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/utest.gtest.xml")
set_tests_properties(utest PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/utest" TIMEOUT "60" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;40;ament_add_gtest;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
add_test(cppcheck "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/cppcheck.xunit.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/humble/bin/ament_cppcheck" "--xunit-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/cppcheck.xunit.xml" "--include_dirs" "/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;66;ament_add_test;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;87;ament_cppcheck;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;57;ament_package;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
add_test(cpplint "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/cpplint.xunit.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_cpplint/cpplint.txt" "--command" "/opt/ros/humble/bin/ament_cpplint" "--xunit-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/cpplint.xunit.xml")
set_tests_properties(cpplint PROPERTIES  LABELS "cpplint;linter" TIMEOUT "120" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_cpplint/cmake/ament_cpplint.cmake;68;ament_add_test;/opt/ros/humble/share/ament_cmake_cpplint/cmake/ament_cmake_cpplint_lint_hook.cmake;39;ament_cpplint;/opt/ros/humble/share/ament_cmake_cpplint/cmake/ament_cmake_cpplint_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;57;ament_package;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/lint_cmake.xunit.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/humble/bin/ament_lint_cmake" "--xunit-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;57;ament_package;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/uncrustify.xunit.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/humble/bin/ament_uncrustify" "--xunit-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;70;ament_add_test;/opt/ros/humble/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;43;ament_uncrustify;/opt/ros/humble/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;57;ament_package;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/xmllint.xunit.xml" "--package-name" "costmap_queue" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/ament_xmllint/xmllint.txt" "--command" "/opt/ros/humble/bin/ament_xmllint" "--xunit-file" "/home/edwinooi/Desktop/foxy_ws/build/costmap_queue/test_results/costmap_queue/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;57;ament_package;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_dwb_controller/costmap_queue/CMakeLists.txt;0;")
subdirs("gtest")
