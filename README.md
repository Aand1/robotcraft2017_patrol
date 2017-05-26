# robotcraft2017_patrol v0.0.2 (May 2017)

----
## General Info

*robotcraft2017_patrol* package for [ROS Kinetic Kame](http://wiki.ros.org/kinetic)

Author: David Portugal, Ingeniarius Ltd.

This package contains the basic framework to run a multi-robot patrolling experiment using the Stage Simulator and ROS.

This is part of the ROS course of [RobotCraft, class of 2017](http://robotcraft.ingeniarius.pt/site/).

----
## Development
Robotcrafters, please inspect and modify the _patrolbot.cpp_ source file (in the "src" folder) to program your own robots' behavior.

----
## Usage

To start up the framework, please do:

```
roslaunch robotcraft2017_patrol robotcraft2017.launch
```

And in a separate terminal, run the example (3 robots at the same time):

```
roslaunch robotcraft2017_patrol start_robots.launch
```

### Tip:
Instead of launching all robots together (last command), you may test each robot's behavior in a separate terminal:

```
rosrun robotcraft2017_patrol patrolbot robot_id:=0
```

```
rosrun robotcraft2017_patrol patrolbot robot_id:=1
```

```
rosrun robotcraft2017_patrol patrolbot robot_id:=2
```

----
## Instructions
Please find detailed installation instructions [**HERE**](http://ingeniarius.pt/davidbsp/robotcraft2017/instructions.pdf).
