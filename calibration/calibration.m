clear;clc;close all;
% load('./data.mat');
load('./stable_longtime.mat');
len = length(qvo(:,1));
attitude_err = zeros(len,3);
attitude_vo = zeros(len,3);
attitude_imu = zeros(len,3);
for i=1:len
   cnbvo = q2mat3x3(qvo(i,:));
   cnbimu = q2mat3x3(qimu(i,:));
   cnb = cnbvo * cnbimu';
   attitude_err(i,:) = cnb2att(cnb);
   attitude_imu(i,:) = cnb2att(cnbimu);
   attitude_vo(i,:) = cnb2att(cnbvo);
   for j=1:3
       if attitude_err(i,j)>180
            attitude_err(i,j) =  attitude_err(i,j) - 360;
       end
%         if attitude_imu(i,j)>pi
%             attitude_imu(i,j) =  attitude_imu(i,j) - 2*pi;
%         end
%        if attitude_vo(i,j)>pi
%             attitude_vo(i,j) =  attitude_vo(i,j) - 2*pi;
%        end
       
       
   end
end
t = (1:length(attitude_err))/25;
figure;
plot(t,attitude_err(:,1),'r');hold on;
plot(t,attitude_err(:,2),'g');
plot(t,attitude_err(:,3),'b');
legend('Yaw','Pitch','Roll');
title('Attitude errors between IMU and SLAM ')
xlabel('Time(sec)'),ylabel('Attitude Error/deg');

figure;
plot(t,attitude_vo(:,1),'r');hold on;
plot(t,attitude_vo(:,2),'g');
plot(t,attitude_vo(:,3),'b');
legend('Yaw','Pitch','Roll');
title('Attitude VO ')
xlabel('Time(sec)'),ylabel('Attitude/deg');

figure;
plot(t,attitude_imu(:,1),'r');hold on;
plot(t,attitude_imu(:,2),'g');
plot(t,attitude_imu(:,3),'b');
legend('Yaw','Pitch','Roll');
title('Attitude errors between IMU and SLAM ')
xlabel('Time(sec)'),ylabel('Attitude Error/deg');

sum=0;

for i=1:len
   sum = sum + attitude_vo(i,1)^2;
end
sigema= sqrt(sum/len)
std_err_3sigma = [std(attitude_vo(:,1));std(attitude_vo(:,2));std(attitude_vo(:,3))]