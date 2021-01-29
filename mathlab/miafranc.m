%%
clear all; clc

%% 
% mintav�telez�si frekvencia be�ll�t�sa
fs = 256;
% id?vektor l�trehoz�sa.
% (mintha minden 1/fs id?pillanatban mint�t vett�nk volna a folytonos
% jelb?l)
t = 1; % t=1 eset�n 1 Hz-es szinusz eset�n egy peri�dust kapunk
time = 0:1/fs:t-1/fs;
% megj.: itt vigy�zzatok a jel�l�sekkel, n�zz�tek hozz� az el?ad�s anyagot,
% az seg�ti a meg�rt�st
%% 
% frekvenci�k, melyeket el? akarjuk �ll�tani
f1 = 10;
f2 = 0.5; % A=2
%f3 = 4;

%%
% jelek l�trehoz�sa
% k�rfrekvinci�v� kell �talak�tani a sin belsej�ben a frekvenci�t
signal1 = sin(2*pi*f1*time);
%signal1= ones(256);
%signal1(1:127) = 1;

%signal2 = sin(2*pi*f2*time);     % 2-es szorz�: amplit�d� �ll�t�sa
%signal3 = cos(2*pi*f3*time);

% jelek �sszege
x = signal1 %+ signal2 %+ signal3;
%%
figure;
plot(time,signal1,'b:','LineWidth',2)
hold on;
%plot(time,signal2,'c--');
plot(time,x,'r-','LineWidth',1.5);
title('Signals in time domain')
xlabel('$Time [t]$','interpreter','latex')
ylabel('$f(t)$','interpreter','latex')
%legend('$sin(2\pi 10t)$','$2sin(2\pi 15t)$','$cos(2\pi 4t)$','$sum(s1,s2,s3)$','interpreter','latex')

%%
% 0 frekvencia komponens k�z�pre ker�lj�n-e vagy a pozit�v oldali
% frekvenciatartom�nyt �br�zoljk
zerocenterd = true;
n = length(x);
if zerocenterd
    % Fourier transzform�ci�
    X_fft = fft(x);
    % 0 frekvencia k�z�pre tev�se
    X = fftshift(X_fft);
    % elshiftelt frekvenciavektor l�trehoz�sa
    f = (-n/2:n/2-1)*(fs/n);
else
    % fourier transzform�ci�
    X = fft(x);
    % frekvenciavektor l�trehoz�sa 
    f = (0:n-1)*(fs/n);
end
% amplit�dokarakteresztika szam�tasa
% az fft elemsz�m�val val� oszt�s: norm�l�s, a Fourier transzform�ci�
% magass�g�t �ll�tja
magnitude = abs(X)/length(X);
% DFT sz�m�t�si hib�inak kisz?r�se
Xy(magnitude < 1e-6) = 0;
% f�zis sz�m�t�sa
phase = unwrap(angle(X));

%%
figure;
% 2x1-es subplot l�trehoz�sa, els? plotra hivatkoz�s
subplot(2,1,1)
plot(f, magnitude,'.b')
title('Magnitude')

% 2x1-es subplot m�sodik plotra hivatkoz�s
subplot(2,1,2)
plot(f,phase*180/pi)
title('Phase')