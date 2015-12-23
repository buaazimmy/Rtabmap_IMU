#include "rtabmap/core/ImuThread.h"
#include "rtabmap/core/ImuEvent.h"
#include "rtabmap/utilite/ULogger.h"

namespace rtabmap {

ImuThread::ImuThread()
{
	_imu = new IMU;
	_serial_port = new Serial_Port;
	_serial_port->start();
	UDEBUG("ImuThread initialized\n");
}

ImuThread::~ImuThread()
{
	_serial_port->stop();
	this->unregisterFromEventsManager();
	this->join(true);
	UDEBUG("ImuThread uninitialized\n");
	UDEBUG("");
}

void ImuThread::handleEvent(UEvent * event)
{
	if(this->isRunning())
	{
//		if(event->getClassName().compare("CameraEvent") == 0)
//		{
//			CameraEvent * cameraEvent = (CameraEvent*)event;
//			if(cameraEvent->getCode() == CameraEvent::kCodeData)
//			{
//				this->addData(cameraEvent->data());
//			}
//			else if(cameraEvent->getCode() == CameraEvent::kCodeNoMoreImages)
//			{
//				this->post(new CameraEvent()); // forward the event
//			}
//		}
//		else if(event->getClassName().compare("OdometryResetEvent") == 0)
//		{
//			_resetOdometry = true;
//		}
		UDEBUG("ImuThread handleEvent\n");
	}
}

void ImuThread::mainLoopKill()
{
//	_dataAdded.release();
}

//============================================================
// MAIN LOOP
//============================================================
void ImuThread::mainLoop()
{
	//TODO core dumped happened sometimes
	if(_serial_port->read_port(ch)<=0)
		UDEBUG("\nSerial port get data error\n");
	if (_imu->rev_process(ch)) {
		this->post(new ImuEvent(*_imu, " "));
	}
}

//void ImuThread::addData(const std::vector<float> & data)
//{
//	bool notify = true;
//	_dataMutex.lock();
//	{
//		_dataBuffer.push_back(data);
//		while(_dataBufferMaxSize > 0 && _dataBuffer.size() > _dataBufferMaxSize)
//		{
//			UDEBUG("Data buffer is full, the oldest data is removed to add the new one.");
//			_dataBuffer.pop_front();
//			notify = false;
//		}
//	}
//	_dataMutex.unlock();
//
//	if(notify)
//	{
//		_dataAdded.release();
//	}
//}
//
//bool ImuThread::getData(std::vector<float> & data)
//{
//	bool dataFilled = false;
//	_dataAdded.acquire();
//	_dataMutex.lock();
//	{
//		if(!_dataBuffer.empty())
//		{
//			data = _dataBuffer.front();
//			_dataBuffer.pop_front();
//			dataFilled = true;
//		}
//	}
//	_dataMutex.unlock();
//	return dataFilled;
//}

} // namespace rtabmap
