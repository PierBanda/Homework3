# Homework3
------------------------------
## Autori ##
Pierluigi Bandino

Remelli Thomas

## Descrizione ##
L'Homework 3 consiste nell'elaborazione di una bag esistente per poi ricavarne un Point Cloud in un file PCL.
Successivamente verranno visualizzati e clusterizzati i punti ricavati.

## Prerequisiti
**ORB_SLAM:** https://github.com/raulmur/ORB_SLAM2

**BAG:** http://robotics.ethz.ch/~asl-datasets/ijrr_euroc_mav_dataset/vicon_room1/V1_01_easy/V1_01_easy.bag

## Istruzioni
Aprire un Terminale ed eseguire i seguenti comandi:
```
mkdir git
cd git
sudo apt-get install -y libglew-dev cmake
git clone https://github.com/stevenlovegrove/Pangolin.git
git clone https://github.com/raulmur/ORB_SLAM2.git
git clone https://github.com/PierBanda/Homework3.git
cp -r -v Homework3/ORB_SLAM2
cd Pangolin
mkdir build && cd build
cmake ..
make
cd ../..
cd ORB_SLAM2
chamod +x build.sh
./buils.sh
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:$(pwd)/Examples/ROS
chmod +x build_ros.sh
./build_ros.sh
```

Eseguire la **bag**:
```
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:PATH/ORB_SLAM2/Examples/ROS
rosrun ORB_SLAM2 Stereo Vocabulary/ORBvoc.txt Examples/Stereo/EuRoC.yaml true
```

Fare partire la **bag**:
```
rosbag play --pause V1_01_easy.bag /cam0/image_raw:=/camera/left/image_raw /cam1/image_raw:=/camera/right/image_raw
```

Spostarsi nella direcroty ORB_SLAM2 ed eseguire lo script per **view** e **cluster**:
```
./pclClustering.sh
```