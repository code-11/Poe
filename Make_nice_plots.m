%Script to clean data and do coordinate transformations
cleanData = [(data(:,1:2)./180).*pi,data(:,4)];
cleanData(:,2) = (cleanData(:,2)-(pi/2));
r=data(:,4);
y=r.*sin(cleanData(:,2));
r_xy=r.*cos(cleanData(:,2));
x = r_xy.*cos(cleanData(:,1));
h = r_xy.*sin(cleanData(:,1));

% Throw out bad data script 
% for i = 1:length(x)
% if ((x(i)<0) || x(i)>30)
% c(i)=0
% else
% c(i)=x(i)
% end
% end

% Do slightly more complicated coordinate transformations (Not needed)
% Pos = zeros(size(cleanData));
% for i = 1:length(cleanData(:,1))
%     phi = cleanData(i,1);
%     theta = cleanData(i,2);
%     r = cleanData(i,3);
%     pos = [r*cos(theta);r*sin(theta);0;0];
%     Ry = [cos(phi),0,sin(phi),0;
%         0,1,0,0;
%         -sin(phi),0,cos(phi),0;
%         0,0,0,1];
%     pos = Ry*pos;
%     Pos(i,:) = pos(1:3);
% end
