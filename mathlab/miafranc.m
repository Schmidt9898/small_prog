%%
clear all; clc

%% 
% mintavételezési frekvencia beállítása
fs = 256;
% id?vektor létrehozása.
% (mintha minden 1/fs id?pillanatban mintát vettünk volna a folytonos
% jelb?l)
t = 1; % t=1 esetén 1 Hz-es szinusz esetén egy periódust kapunk
time = 0:1/fs:t-1/fs;
% megj.: itt vigyázzatok a jelölésekkel, nézzétek hozzá az el?adás anyagot,
% az segíti a megértést
%% 
% frekvenciák, melyeket el? akarjuk állítani
f1 = 10;
f2 = 0.5; % A=2
%f3 = 4;

%%
% jelek létrehozása
% körfrekvinciává kell átalakítani a sin belsejében a frekvenciát
signal1 = sin(2*pi*f1*time);
%signal1= ones(256);
%signal1(1:127) = 1;

%signal2 = sin(2*pi*f2*time);     % 2-es szorzó: amplitúdó állítása
%signal3 = cos(2*pi*f3*time);

% jelek összege
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
% 0 frekvencia komponens középre kerüljön-e vagy a pozitív oldali
% frekvenciatartományt ábrázoljk
zerocenterd = true;
n = length(x);
if zerocenterd
    % Fourier transzformáció
    X_fft = fft(x);
    % 0 frekvencia középre tevése
    X = fftshift(X_fft);
    % elshiftelt frekvenciavektor létrehozása
    f = (-n/2:n/2-1)*(fs/n);
else
    % fourier transzformáció
    X = fft(x);
    % frekvenciavektor létrehozása 
    f = (0:n-1)*(fs/n);
end
% amplitúdokarakteresztika szamítasa
% az fft elemszámával való osztás: normálás, a Fourier transzformáció
% magasságát állítja
magnitude = abs(X)/length(X);
% DFT számítási hibáinak kisz?rése
Xy(magnitude < 1e-6) = 0;
% fázis számítása
phase = unwrap(angle(X));

%%
figure;
% 2x1-es subplot létrehozása, els? plotra hivatkozás
subplot(2,1,1)
plot(f, magnitude,'.b')
title('Magnitude')

% 2x1-es subplot második plotra hivatkozás
subplot(2,1,2)
plot(f,phase*180/pi)
title('Phase')