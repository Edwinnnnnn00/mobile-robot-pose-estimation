# Copyright 2019 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Get the urdf file
    TURTLEBOT3_MODEL = os.environ['TURTLEBOT3_MODEL']
    model_folder = 'turtlebot3_' + TURTLEBOT3_MODEL
    urdf_path1 = os.path.join(
        get_package_share_directory('turtlebot3_gazebo'),
        'models',
        model_folder,
        'model1_with_marker.sdf'
    )

    urdf_path2 = os.path.join(
        get_package_share_directory('turtlebot3_gazebo'),
        'models',
        model_folder,
        'model2_with_marker.sdf'
    )

    # Launch configuration variables specific to simulation
    x_pose1 = LaunchConfiguration('x_pose1', default='1.0')
    x_pose2 = LaunchConfiguration('x_pose2', default='1.5')
    y_pose = LaunchConfiguration('y_pose', default='1.0')

    # Declare the launch arguments
    declare_x_position1_cmd = DeclareLaunchArgument(
        'x_pose1', default_value='1.0',
        description='Specify namespace of the robot')
    
    declare_x_position2_cmd = DeclareLaunchArgument(
        'x_pose2', default_value='1.5',
        description='Specify namespace of the robot')

    declare_y_position_cmd = DeclareLaunchArgument(
        'y_pose', default_value='1.0',
        description='Specify namespace of the robot')

    start_gazebo_ros_spawner_cmd1 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_entity1',
        namespace='waffle_pi1',
        arguments=[
            '-entity', TURTLEBOT3_MODEL+'1',
            '-file', urdf_path1,
            '-x', x_pose1,
            '-y', y_pose,
            '-z', '0.01',
            # '-gazebo_namespace', 'waffle_pi1',
            # '-robot_namespace', 'waffle_pi1',
        ],
        output='screen',
    )


    start_gazebo_ros_spawner_cmd2 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_entity2',
        namespace='waffle_pi2',
        arguments=[
            '-entity', TURTLEBOT3_MODEL+'2',
            '-file', urdf_path2,
            '-x', x_pose2,
            '-y', y_pose,
            '-z', '0.01',
            # '-gazebo_namespace', 'waffle_pi1',
            # '-robot_namespace', 'waffle_pi2',
        ],
        output='screen',
    )

    ld = LaunchDescription()

    # Declare the launch options
    ld.add_action(declare_x_position1_cmd)
    ld.add_action(declare_x_position2_cmd)
    ld.add_action(declare_y_position_cmd)

    # Add any conditioned actions
    ld.add_action(start_gazebo_ros_spawner_cmd1)
    ld.add_action(start_gazebo_ros_spawner_cmd2)

    return ld
