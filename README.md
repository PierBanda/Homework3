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
Aprire il Terminale e scaricare la Repository **Homework3**:
```
git clone https://github.com/PierBanda/Homework3.git
```

Spostarsi nella Directory **Homework3** ed eseguire **build.sh**:
```
cd Homework3 && ./build.sh
```

Eseguire il nodo **roscore**:
```
roscore
```

Eseguire la **bag**:
```
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:PATH/ORB_SLAM2/Examples/ROS
rosrun ORB_SLAM2 Stereo Vocabulary/ORBvoc.txt Examples/Stereo/EuRoC.yaml true
```

Caricare il **visualizzatore**:
```
rosrun ORB_SLAM2 Stereo PATH_TO_VOCABULARY PATH_TO_SETTINGS_FILE ONLINE_RECTIFICATION
```

Fare partire la **bag**:
```
rosbag play --pause V1_01_easy.bag /cam0/image_raw:=/camera/left/image_raw /cam1/image_raw:=/camera/right/image_raw
```

Spostarsi nella direcroty ORB_SLAM2 ed eseguire lo script per **view** e **cluster**:
```
./pclClustering.sh
```