X = [1 0.5 ; 0.5 1 ];
Xinv = inv(X);
r = [1,-0.2];
%w = r*Xinv;
w = [1 0];
%%
w = w - 1*(X*w' - r);



%%
a=
b=
c=

x1=(-b+sqrt(b*b-4*a*c))/2;

x2=(-b-sqrt(b*b-4*a*c))/2;

