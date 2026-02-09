FROM osrf/ros:humble-desktop

# Add ubuntu user with same UID and GID as your host system, if it doesn't already exist
# Since Ubuntu 24.04, a non-root user is created by default with the name vscode and UID=1000
ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN if ! id -u $USER_UID >/dev/null 2>&1; then \
    groupadd --gid $USER_GID $USERNAME && \
    useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME; \
    fi
# Add sudo support for the non-root user
RUN apt-get update && \
    apt-get install -y sudo && \
    echo "$USERNAME ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME

# Switch from root to user
USER $USERNAME

# Add user to video group to allow access to webcam
RUN sudo usermod --append --groups video $USERNAME

# Update all packages
RUN sudo apt update && sudo apt upgrade -y

# Install Git
RUN sudo apt install -y git

# Rosdep update
RUN rosdep update

# Source the ROS setup file
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc


################################
## ADD ANY CUSTOM SETUP BELOW ##
################################


# --- Установка текстового редактора
RUN sudo apt install gedit -y
# RUN sudo apt install nano -y

RUN sudo apt install tree -y

# --- Установка python3
# RUN sudo apt install software-properties-common -y
# RUN sudo add-apt-repository ppa:deadsnakes/ppa -y
# RUN sudo apt update
# RUN sudo apt install python3.14 -y
# RUN sudo apt install python3.11-pip -y
RUN sudo apt install python3-pip -y

# --- Установка NetworkX
# RUN sudo pip install networkx[default]

# --- Install Gazebo (https://gazebosim.org/docs/fortress/install_ubuntu/) or (https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/#pc-setup)
RUN sudo apt-get install ros-${ROS_DISTRO}-ros-gz -y
RUN sudo apt install ros-${ROS_DISTRO}-gazebo-* -y
RUN sudo curl https://packages.osrfoundation.org/gazebo.gpg --output /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
RUN sudo apt-get update -y
# RUN sudo apt install ros-humble-gazebo-ros-pkgs -y
RUN sudo apt-get install ignition-fortress -y

# --- Install Moveit
RUN sudo apt install ros-humble-moveit -y

# --- Install Cartographer
RUN sudo apt install ros-humble-cartographer -y
RUN sudo apt install ros-humble-cartographer-ros -y

# --- Install Navigation2
RUN sudo apt install ros-humble-navigation2 -y
RUN sudo apt install ros-humble-nav2-bringup -y

# Install the required TurtleBot3 Packages (https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/)

# RUN sudo apt install ros-humble-turtlebot3  # иногда можно установить так просто

## --- --- Выполняется только при первой сборке (если папка turtlebot3_ws существует, то повторять выполнять не треубется):
# 'ly_ROS2_humble' - директрия с папкой .devcontainer
# RUN bash -c 'source /opt/ros/humble/setup.bash'
# RUN sudo mkdir -p /ly_ROS2_humble/turtlebot3_ws/src
# RUN cd /ly_ROS2_humble/turtlebot3_ws/src/
# RUN sudo git clone -b humble https://github.com/ROBOTIS-GIT/DynamixelSDK.git
# RUN sudo git clone -b humble https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
# RUN sudo git clone -b humble https://github.com/ROBOTIS-GIT/turtlebot3.git
# RUN sudo apt install python3-colcon-common-extensions -y
# RUN cd /ly_ROS2_humble/turtlebot3_ws
# RUN colcon build --symlink-install

# --- --- Выполняется при пересборке пакета rebuild:
# Устновка ROS окружения
# RUN echo 'source /ly_ROS2_humble/turtlebot3_ws/install/setup.bash' >> ~/.bashrc
# RUN bash -c 'source ~/.bashrc'
RUN echo 'export ROS_DOMAIN_ID=30 #TURTLEBOT3' >> ~/.bashrc
RUN echo 'source /usr/share/gazebo/setup.sh' >> ~/.bashrc
# RUN echo 'source /opt/ros/humble/setup.bash' >> ~/.bashrc
RUN bash -c 'source ~/.bashrc'