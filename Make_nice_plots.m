cleanData = [(data(:,1:2)./180).*pi,data(:,4)];
r=data(:,4);
h=r.*sin(cleanData(:,1));
r_xy=r.*cos(cleanData(:,1));
x = r_xy.*cos(cleanData(:,2));
y = r_xy.*sin(cleanData(:,2));
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
