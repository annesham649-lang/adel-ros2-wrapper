# ADEL 2.0 ROS 2 Wrapper (Space Nova)

Bare-metal C++/Rust execution wrapper for integrating Space Nova's **ADEL 2.0** (Autonomous Deterministic Executive Layer) into standard ROS 2 node topologies.

## Quick Links
* **Live Interactive Monitor & Benchmarks:** https://space-nova-monitor-2026.streamlit.app/


## Build Instructions (ROS 2 Humble / Iron / Rolling)

```bash
# Clone into your ROS 2 workspace src directory
cd ~/ros2_ws/src
git clone [https://github.com/annesham649-lang/adel-ros2-wrapper.git](https://github.com/annesham649-lang/adel-ros2-wrapper.git)

# Build package
cd ~/ros2_ws
colcon build --packages-select adel_ros2_wrapper

# Source and Run
source install/setup.bash
ros2 run adel_ros2_wrapper adel_node
