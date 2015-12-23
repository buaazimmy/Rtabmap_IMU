/*
 * ImuEvent.h
 *
 *  Created on: Dec 18, 2015
 *      Author: zim
 */

#pragma once

#include <rtabmap/utilite/UEvent.h>
#include "rtabmap/core/imu.h"

namespace rtabmap {

class ImuEvent: public UEvent {
public:
	enum Code {
		kCodeData, kCodeNoMoreData
	};

public:
	ImuEvent() :
			UEvent(kCodeNoMoreData) {
	}

	ImuEvent(const IMU & data, const std::string & imuName = "") :
			UEvent(kCodeData), data_(data), imuName_(imuName) {
	}

	// Image or descriptors
	const IMU & data() const {
		return data_;
	}
	const std::string & imuName() const {
		return imuName_;
	}

	virtual ~ImuEvent() {
	}
	virtual std::string getClassName() const {
		return std::string("ImuEvent");
	}

private:
	IMU data_;
	std::string imuName_;
};

} // namespace rtabmap
