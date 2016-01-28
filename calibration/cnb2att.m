function att = cnb2att(cnb)

    thita = asin(cnb(2,3));
    if ((-cnb(1,3))>=0&&cnb(3,3)>0)            
        gama = atan(-cnb(1,3)/cnb(3,3));
    elseif ((-cnb(1,3))>=0&&cnb(3,3)<0)            
        gama = atan(-cnb(1,3)/cnb(3,3))+pi;
    elseif ((-cnb(1,3))<=0&&cnb(3,3)>0)            
        gama = atan(-cnb(1,3)/cnb(3,3));
    elseif ((-cnb(1,3))<=0&&cnb(3,3)<0)            
        gama = atan(-cnb(1,3)/cnb(3,3))-pi;
    elseif (cnb(3,3)==0&&(-cnb(1,3))<0)            
        gama = 3*pi/2;            
    else
        gama = pi/2;
    end
    if (cnb(2,2)>0&&(-cnb(2,1))>=0)            
        kfai = atan((-cnb(2,1))/cnb(2,2));
    elseif (cnb(2,2)>0&&(-cnb(2,1))<=0)            
        kfai = atan((-cnb(2,1))/cnb(2,2))+2*pi;
    elseif (cnb(2,2)<0&&(-cnb(2,1))>=0)            
        kfai = atan((-cnb(2,1))/cnb(2,2))+pi;
    elseif (cnb(2,2)<0&&(-cnb(2,1))<=0)           
        kfai = atan((-cnb(2,1))/cnb(2,2))+pi;
    elseif (cnb(2,2)==0&&(-cnb(2,1))<0)           
        kfai = 3*pi/2;            
    else
        kfai = pi/2;
    end

    att=[thita; gama; kfai]*180/pi;
end