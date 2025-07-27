clc; clear all; close all;

a = 1;
n = 0:0.1:1;
f = 1;
x = a * sin(2*pi*f*n);
subplot(3,2,1);
stem(n,x);
xlabel('Time');
ylabel('Amplitude');
title('Sine Signal');

%Upsampling
xu = upsample(x,2);
subplot(3,2,2);
stem(xu);
xlabel('Time');
ylabel('Amplitude');
title('Upsampled Sine Signal');

%Interpolation
xi = interp(x,2);
subplot(3,2,3);
stem(xi);
xlabel('Time');
ylabel('Amplitude');
title('Interpolated Sine Signal');

%Downsampling
xd = downsample(x,2);
subplot(3,2,4);
stem(xd);
xlabel('Time');
ylabel('Amplitude');
title('Downsampled Sine Signal');

%Downsampling
xr = resample(x,3,2);
subplot(3,2,5);
stem(xr);
xlabel('Time');
ylabel('Amplitude');
title('Resampled Sine Signal');