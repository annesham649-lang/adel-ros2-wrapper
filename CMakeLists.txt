cmake_minimum_required(VERSION 3.8)
project(adel_ros2_wrapper)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(adel_node src/adel_node.cpp)
ament_target_dependencies(adel_node rclcpp std_msgs)

install(TARGETS
  adel_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
