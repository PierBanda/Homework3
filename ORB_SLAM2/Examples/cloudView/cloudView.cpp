#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <sstream>
#include <iostream>   // std::cout
#include <string>     // std::string, std::stod
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h> 

int main(int argc, char **argv) 
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster(new pcl::PointCloud<pcl::PointXYZ> ());
  
  // Load a cloud from file
  if ( pcl::io::loadPCDFile(argv[1], *cloud_cluster ) < 0)
  {
    std::cout << "Error loading model cloud." << std::endl;
    return (-1);
  }
 
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("PCD Map original"));
  viewer->setBackgroundColor (0.1, 0.1, 0.1);
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> 
      cluster_color(cloud_cluster, 0, 200, 0);
    // Visualize this cluster
    viewer->addPointCloud<pcl::PointXYZ> ( cloud_cluster, cluster_color, "cloud");

  // Wait until the visualizer is closed
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce ( 1 );
  }
}
