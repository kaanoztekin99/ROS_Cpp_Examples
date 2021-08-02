# ROS_Cpp_Examples
## Aim Of Project: 
Creating ROS Publisher-Subscriber, Service and Action Server-Client Examples
</br>
</br>
### IMPORTANT NOTE :
- In this project, I did all the steps that need to be done.
- Just install ROS-noetic version and project
- Apply all the remain parts.
- Don't forget to use the catkin_make command in the catkin workspace after making any changes to the files.


## Prerequisites : (Explained in README File)
* What is ROS and how does it work ?
* How to create and work on ROS workspace ?
* How to create and build our own package ?
* What are nodes ?
* What is topic ?
* What are the msg, srv, action files ?

## Examples
* Publisher-Subscriber Example with C++
* Service Server-Client Example with C++
* Action Server-Client Example with C++
</br>

### What is ROS and how does it work ?
- Robot Operating System is a flexible framework for writing robot software. It's a collection of tools, libraries and conventions that aim to simplify the task of creating complex and robot behavior across a wide variety of robotic plaforms.
- We need to install ROS - noetic version because i used [Ubuntu 20.04](https://ubuntu.com/download/desktop)
- We are going to use these commands :

```
$ sudo apt update
$ sudo apt install ros-noetic-desktop-full
```
- Environment setup :
```
$ source /opt/ros/noetic/setup.bash
$ sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
$ sudo apt install python3-rosdep
$ sudo rosdep init
$ rosdep update
```
</br>

### How to create and work on ROS workspace ?
- A catkin workspace is a folder where you modify, build, and 
install catkin packages.
- Workspace: Set of directories where we store related pieces of ROS code.
- To create a workspace we should apply the following commands :
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
$ source devel/setup.bash
$ echo $ROS_PACKAGE_PATH
/home/toztekin/catkin_ws/src:/opt/ros/noetic/share
```
</br>

### How to create and build our own package ?
- Packages contain configuration file to start other packages or nodes.
- Packages are organized as follows:
  - Launch Folder
  - src Folder
  - CMakeLists.txt
  - package.xml
- All ROS packages need to reside inside a catkin workspace.(catkin_ws)
- To create a package we should apply the following commands :
```
$ cd ~/catkin_ws/src
$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
$ cd ~/catkin_ws
$ catkin_make
$ . ~/catkin_ws/devel/setup.bash
$ source /opt/ros/noetic/setup.bash
$ catkin_make
$ ls

    build
    devel
    src
```
</br>

### What are nodes ?
- It is the smallest processor unit running in ROS. It is compiled using ROS. 
- A separate node must be created for each purpose.
- Nodes can post messages to a topic and subscribe to a topic to receive messages.  
</br>[ROS Master]: It acts as a server for node-to-node connections and message communication. 
</br>[Roscore]: It acts as a server for node-to-node connections and message communication. 
</br>
</br>- roscore = ros+core : master (provides name service for ROS) + rosout (stdout/stderr) + parameter server (parameter server will be introduced later)
</br>- rosnode = ros+node : ROS tool to get information about a node.
</br>- rosrun = ros+run : runs a node from a given package.
</br>

### What is topic ?
- They are data paths on which nodes exchange messages. 
- More than one publisher on a topic - can subscribe. 
</br>[rostopic] : see the status.
</br>[rostopic list] : active topics are listed.
</br>[rostopic list -v] : more detailed list of active topics.
</br>[rostopic echo topicname] : shows the messages on the topic called with topic_name
</br>

## What are the msg, srv, action files ?
***msg***: Simple text files containing messages using within ROS domains 
</br>***srv***: Files that define services. Two-way simultaneous communication.  (request - respond)
</br>***action***: Two-way simultaneous communication. (Goal - Feedback - Result)
</br>
</br>
***IMPORTANT !***
</br>
Every message, action or srv file we write, we should define them to CMakeLists.txt and package.xml file. Otherwise we will get an ERROR while we were trying catkin_make.
</br>
For more information you should check [this website](http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv)
</br>
I did all the steps that need to be done. Don't forget to use the catkin_make command in the catkin workspace after making any changes to the files. 
</br>
</br>
</br>
</br>


### Publisher-Subscriber Example with C++
***Publish:*** It is the act of transmitting related terms corresponding to the subject.
</br>***Publisher Node:*** It saves its own information and topic to the master. It sends messages to nodes interested in the same topic. 
</br>***Subscribe:*** It is the act of receiving messages related to the topic. 
</br>***Subscriber Node:*** It saves its own information and topic to the master as publisher. Retrieves the information of the publisher who published the relevant topic from the master.
</br>

- We are going to run roscore
- In another terminal window, we should run our talker and listener (publisher and subscriber nodes) to do this:
```
$ cd ~/my_ws/
$ source ./devel/setup.bash
$ rosrun beginner_tutorials talker (and listener in another terminal) 
```
>In different terminal windows we run both nodes (talker and listener).
>![package](https://user-images.githubusercontent.com/56647896/127859321-bbe85199-7df2-43d8-a440-16ce86efe784.png)
</br>

>You can have a look at the screenschot of my listener talker nodes. Our talker sends the message and listener takes the message from him.
>![nodes](https://user-images.githubusercontent.com/56647896/127859525-868b9e2f-23dc-43e0-bb5d-a84994943c14.png)


- to see the topic is working we are going to use rostopic list and here /chatter is our topic name.
-  For more detailed information you can have a look at our script.
```
$ cd ~/my_ws/
$ rostopic list
$ rostopic echo /chatter
```
>Here we can see our active topics and the message we have used in chatter topic
>![topic](https://user-images.githubusercontent.com/56647896/127859269-a4cb1e08-eb97-4206-af1e-53265309df8d.png)

***Final Publisher - Subscriber Project***
>Screenshot of our finished example. (Contains master - publisher(talker) node - rostopic and message - subscriber(listener) node)
>![allproject](https://user-images.githubusercontent.com/56647896/127859631-931ff3b4-7e6b-4fdf-a4f5-74f81b401cc1.png)
</br>
</br>
</br>
</br>


### Service Server-Client Example with C++
***Service:*** Communication over the service is a two-way simultaneous communication between the service client and the service server.
</br>Services are another way nodes can communicate with each other.
</br>***Service Server:*** In service communication, it takes the service client's request as input and transmits the response as output. 
</br>Unlike topics, the service is a one-time message communication. 
</br>***ROS Service:*** It is used to command a robot to perform a certain action or to have nodes perform events with a certain condition. 
</br>
- We are going to run roscore
- In another terminal window, we should run our service server and client to do this:
```
$ cd ~/my_ws/
$ source ./devel/setup.bash
$ rosrun beginner_tutorials add_two_ints_server (and add_two_ints_client in another terminal) 
```
>Here, our service is working
>![serverIsWorking](https://user-images.githubusercontent.com/56647896/127864074-9009d5f2-414c-4f6c-b738-b7310823c225.png)

</br>

>Then we called our client to respond our server with correct answer
>![clientResponded](https://user-images.githubusercontent.com/56647896/127864176-54d3b4b9-d3eb-40e1-9a68-8e4eae802c84.png)

</br>

>Here we can see our active server and nodes.
>![serviceList](https://user-images.githubusercontent.com/56647896/127864772-83d6e1d9-8d86-44ac-9cfb-d80453c18b8b.png)

</br>
</br>
</br>
</br>
</br>


### Action Server-Client Example with C++
***Action:*** Action is another message communication method used for two-way communication. 
</br>Action is used when it takes longer to respond after receiving a request and feedback is needed until the result is returned.
</br>It has a structure in the form of goals, feedback and results. 
</br>***Action Server:*** Responsible for targeting and responding with feedback or results from the action processor. 
</br>Unlike topics, the service is a one-time message communication. 
</br>***Action Client:*** It is responsible for forwarding the target to the action server. 
- We are going to run roscore
- In another terminal window, we should run our action server and client to do this:
```
$ cd ~/my_ws/
$ source ./devel/setup.bash
$ rosrun beginner_tutorials action_server (and action_client in another terminal) 
```
>Our server sends the start of the Fibonacci then client get a request to create a respond with answer of first 20 Elements of Fibonacci
>![nodes](https://user-images.githubusercontent.com/56647896/127866845-fcc43b56-4dc4-410a-a5ee-8c72288faf66.png)

</br>

>Here we can see the answer as a result of first 20 elements of Fibonacci


>![topic](https://user-images.githubusercontent.com/56647896/127867007-fd121b03-d560-455c-b435-b9ec16576da5.png)
