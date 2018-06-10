# Homework3
------------------------------
## Autori ##
Pierluigi Bandino

Remelli Thomas

## Descrizione ##
Questo progetto fa parte terzo Homework del corso di Laboratorio Ciberfisico e consiste nell'elaborazione di una bag esistente per poi ricavarne un Point Cloud in un file PCL.
Il normale codice sorgente di ORB SLAM verrà modificato per permettere di salvare la mappa alla chiusura tramite ctrl^C in un file PCL.
Successivamente da questo file PCL verranno visualizzati e clusterizzati i punti ricavati.

## Prerequisiti
**ORB_SLAM:** https://github.com/raulmur/ORB_SLAM2

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

Eseguire il nodo **roscore**:
```
roscore
```

Eseguire la **bag**:
```
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:PATH/ORB_SLAM2/Examples/ROS
rosrun ORB_SLAM2 Stereo Vocabulary/ORBvoc.txt Examples/Stereo/EuRoC.yaml true
```

Fare partire la **bag**.
Al posto di (bag) inserire il bercorso della propria BAG.
```
rosbag play --pause (bag) /cam0/image_raw:=/camera/left/image_raw /cam1/image_raw:=/camera/right/image_raw
```

Spostarsi nella direcroty ORB_SLAM2 ed eseguire lo script per **view** e **cluster**:
```
chamod +x pclClustering.sh
./pclClustering.sh (PCL_FILE) (TOLLERANZA)
```

## Immagini dimostrative
![Drag Racing](/Users/UNIVR/Desktop/ImmaginiHW3/bag.jpg)
<img src="/Users/UNIVR/Desktop/ImmaginiHW3/bag.jpg"
     alt="bag image"
     style="float: left; margin-right: 10px;" />
<img src="/Users/UNIVR/Desktop/ImmaginiHW3/orbslam.jpg"
     alt="orbslam image"
     style="float: left; margin-right: 10px;" />
<img src="/Users/UNIVR/Desktop/ImmaginiHW3/map_saved.jpg"
     alt="map image"
     style="float: left; margin-right: 10px;" />
<img src="/Users/UNIVR/Desktop/ImmaginiHW3/view.jpg"
     alt="view image"
     style="float: left; margin-right: 10px;" />
<img src="/Users/UNIVR/Desktop/ImmaginiHW3/cluster.jpg"
     alt="cluster image"
     style="float: left; margin-right: 10px;" />