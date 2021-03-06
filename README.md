# Homework3
------------------------------
## Autori ##
Pierluigi Bandino

Remelli Thomas

## Descrizione ##
Questo progetto fa parte del terzo Homework per il corso di Laboratorio Ciberfisico e consiste nell'elaborazione di una bag con ORBSLAM2 e ricavare un Point Cloud in un file PCL.
Per poter aggiungere la capacità di salvare la nuvola di punti si è modificato il codice originale do Orbslam2, in modo tale che alla chiusura del processo, tramite ctrl^C, la nuvola di punti venga salvata in formato PCL all'interno della cartella pclFile.

Successivamente sarà possibile clusterizzare i punti dal file PCL risultato, in base alla
distanza Euclidea e visualizzarne il risultato eseguendo uno script.

## Prerequisiti
Prima di procedere controllare i vari requisiti alla pagina di **ORB_SLAM:** https://github.com/raulmur/ORB_SLAM2
è richiesto ROS

## Installazione
Aprire un Terminale ed eseguire i seguenti comandi:

scaricare le repository originali:
```
mkdir git
cd git
git clone https://github.com/stevenlovegrove/Pangolin.git
git clone https://github.com/raulmur/ORB_SLAM2.git
```
scaricare i file modificati (nella stessa cartella dove avete scaricato le repositori originali):
```
git clone https://github.com/PierBanda/Homework3.git
cp -r -v Homework3/ORB_SLAM2 .
```
compilare con: 
```
cd Pangolin
mkdir build && cd build
cmake ..
make
cd ../..
cd ORB_SLAM2
chmod +x build.sh
./build.sh
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:$(pwd)/Examples/ROS
chmod +x build_ros.sh
./build_ros.sh
```

## esecuzione
aprire tre terminali
Eseguire **roscore**:
```
roscore
```
Eseguire il nodo **Stereo**:
```
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:PATH/ORB_SLAM2/Examples/ROS
rosrun ORB_SLAM2 Stereo Vocabulary/ORBvoc.txt Examples/Stereo/EuRoC.yaml true
```
Fare partire la **bag**.

**NB** Al posto di (bag) inserire il percorso della propria BAG.
```
rosbag play --pause (bag) /cam0/image_raw:=/camera/left/image_raw /cam1/image_raw:=/camera/right/image_raw
```
**NB** per far partire la bag premere spazio nel terminale dove è stato eseguito il comando.

Esempio utilizzando (http://robotics.ethz.ch/~asl-datasets/ijrr_euroc_mav_dataset/vicon_room1/V1_01_easy/V1_01_easy.bag)

Elaborazione della bag:
![Bag Image](https://github.com/PierBanda/Homework3/blob/master/ImmaginiHW3/bag.jpg "Bag Image")

Elaborazione della nuvola di punti:
![Orbslam Image](https://github.com/PierBanda/Homework3/blob/master/ImmaginiHW3/orbslam.jpg "Orbslam Image")

Salvataggio della mappa:
![Map Image](https://github.com/PierBanda/Homework3/blob/master/ImmaginiHW3/map_saved.jpg "Map Image")

Per poter clusterizzare il file pcl eseguire il seguente comando, all'interno di ORB_SLAM2, dove (PCL_FILE) è il percorso del file pcl e (TOLLERANZA) la tolleranza per l'estrattore dei cluster (espresso in metri), i vari cluster verranno poi salvati nella cartella pclFile:
```
chmod +x pclClustering.sh
./pclClustering.sh (PCL_FILE) (TOLLERANZA)
```
Esempio:
Visualizzazione point cloud:
![View Image](https://github.com/PierBanda/Homework3/blob/master/ImmaginiHW3/view.jpg "View Image")

Visualizzazione cluster tolleranza 0.26:
![Cluster Image](https://github.com/PierBanda/Homework3/blob/master/ImmaginiHW3/cluster.jpg "Cluster Image")

