import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    waffle_pi1_config = os.path.join(get_package_share_directory('localization_server'), 'config', 'waffle_pi1_amcl_config.yaml')
    waffle_pi2_config = os.path.join(get_package_share_directory('localization_server'), 'config', 'waffle_pi2_amcl_config.yaml')

    map_file = os.path.join(get_package_share_directory('map_server'), 'config', 'turtlebot_area.yaml')

    return LaunchDescription([
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'use_sim_time': True}, 
                        {'topic_name':"map"},
                        {'frame_id':"map"},
                        {'yaml_filename':map_file}]
        ),
            
        Node(
            namespace='waffle_pi1',
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[waffle_pi1_config]
        ),

        Node(
             namespace='waffle_pi2',
             package='nav2_amcl',
             executable='amcl',
             name='amcl',
             output='screen',
             parameters=[waffle_pi2_config]
        ),

        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[{'use_sim_time': True},
                        {'autostart': True},
                        {'bond_timeout':0.0},
                        {'node_names': ['map_server', 'waffle_pi1/amcl', 'waffle_pi2/amcl']}]
        )
    ])