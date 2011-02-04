/**
 * @file   real_arm.h
 * @author Ugo Cupcic <ugo@shadowrobot.com>, Contact <contact@shadowrobot.com>
 * @date   Tue Jun 29 14:56:10 2010
 *
 * @brief The real arm is a ROS interface to Shadow Robot muscle arm.
 *
 */

#ifndef REAL_ARM_H_
#define REAL_ARM_H_

#include <robot/config.h>

#include "sr_hand/hand/sr_articulated_robot.h"

namespace shadowrobot
{

class RealArm : public SRArticulatedRobot
{
public:
  /**
   * Initializes the necessary mappings with a static list of names.
   */
  RealArm();
  ///destructor
  ~RealArm();

  //virtual classes defined in SRArticulatedRobot
  /**
   * This function will set the target of the object to the given angle and send it to
   * the robot.
   *
   *
   * @param joint_name The Joint in joints_map you wish to send the target to.
   * @param target The target in degree
   * @return 0 if success ; -1 if error
   */
  virtual short sendupdate(std::string joint_name, double target);

  /**
   * Reads the data from the robot.
   *
   * @param joint_name The name of the joint, as specified in joints_map.
   * @return The information regarding this joint.
   */
  virtual JointData getJointData(std::string joint_name);
  virtual JointsMap getAllJointsData();

  virtual short setContrl(std::string contrlr_name, JointControllerData ctrlr_data);
  virtual JointControllerData getContrl(std::string ctrlr_name);

  virtual short setConfig(std::vector<std::string> myConfig);
  virtual void getConfig(std::string joint_name);

  /**
   * Get diagnostic information from the robot.
   * @return A vector containing all the diagnostics for the hand (motor information, etc...)
   */
  virtual std::vector<DiagnosticData> getDiagnostics();
protected:
  /**
   * Initialise a mapping for the joints.
   */
  void initializeMap();
};

}//end namespace

#endif /* REAL_ARM_H_ */
