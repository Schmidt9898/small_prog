 %%
 clc
 clear
 % x(n), h(n) 
 h = [1/pi 1/2 1/pi 0];
 x = [2 1 -1 1];

% X(k), H(k) 4 pontos FFT-vel 
X = fft(x, 4);
H = fft(h, 4);

% Y(k) kiszamitasa 
Y = X.*H;
megoldas=ifft(Y,4)
%%
% X(k), H(k) 8 pontos FFT-vel
X = fft(x, 8);
H = fft(h, 8);

% Y(k) kiszamitasa
Y = X.*H;
megoldas2 = round(ifft(Y,8)) % 2.0000 1.0000 1.0000 4.0000 0.0000 0.0000 1.0000 0

%%
%amplitudo
clc
clear
%omega vektor letrehozasa 
omega = 0:0.01:2*pi; 
% amplitudospektrum letrehozasa 
H_omega_abs = (abs(exp(1j.*omega) -0.5j).*abs(exp(1j.*omega)+0.5j))./( abs(exp(1j.*omega)+0.5).*abs(exp(1j.*omega)-2)); 
% plottolas 
figure; 
plot(omega ,H_omega_abs ,'Color',[1 0.6 0],'LineWidth',2); 
grid on; 
ylim([0.2,0.9]); 
xticks([0,pi/2,pi,3*pi/2]) 
xlim([0,3*pi/2]) 
ylabel('$|H(\omega)|$','Interpreter','latex') 
xlabel('$\omega/f_{s}$','Interpreter','latex')

%%

clc;
clear;
t= 1/pi


m= (-2i / (2*pi));





%%
%%
%amplitudo
clc
clear
%omega vektor letrehozasa 
omega = 0:0.01:2*pi; 
% amplitudospektrum letrehozasa 
H_omega_abs = exp(-1i*omega)/2; 
% plottolas 
figure; 
plot(omega ,H_omega_abs ,'Color',[1 0.6 0],'LineWidth',2); 
grid on; 
ylim([0.2,0.9]); 
xticks([0,pi/2,pi,3*pi/2]) 
xlim([0,3*pi/2]) 
ylabel('$|H(\omega)|$','Interpreter','latex') 
xlabel('$\omega/f_{s}$','Interpreter','latex')







