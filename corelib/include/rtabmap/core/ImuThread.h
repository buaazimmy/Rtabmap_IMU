/*
 * ImuThread.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: zim
 */

#ifndef IMUTHREAD_H_
#define IMUTHREAD_H_

#include <rtabmap/core/RtabmapExp.h>
#include <rtabmap/core/serial_port.h>
#include <rtabmap/core/imu.h>
#include <rtabmap/utilite/UThread.h>
#include <rtabmap/utilite/UEventsHandler.h>
//#include <vector>
//#include <list>
namespace rtabmap {

class RTABMAP_EXP ImuThread : public UThread, public UEventsHandler {
public:
	ImuThread();
	virtual ~ImuThread();

protected:
	virtual void handleEvent(UEvent * event);

private:
	void mainLoopKill();

	//============================================================
	// MAIN LOOP
	//============================================================
	void mainLoop();
//	void addData(const std::vector<float> & data);
//	bool getData(std::vector<float> & data);

private:
	IMU * _imu;
	Serial_Port * _serial_port;
	unsigned char ch;
//	USemaphore _dataAdded;
//	UMutex _dataMutex;
//	std::list<std::vector<float>> _dataBuffer;
//	unsigned int _dataBufferMaxSize;
};

} // namespace rtabmap


#endif /* IMUTHREAD_H_ */




