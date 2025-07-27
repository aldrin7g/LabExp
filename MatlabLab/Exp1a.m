clc; clear all; close all;

n1 = -5:5;
x1 = [zeros(1,5),ones(1),zeros(1,5)];
subplot(3,2,1);
stem(n1,x1);
xlabel('Time');
ylabel('Amplitude');
title('Unit Impulse Signal');

n2 = -5:5;
x2 = [zeros(1,5),ones(1,6)];
subplot(3,2,2);
stem(n2,x2);
xlabel('Time');
ylabel('Amplitude');
title('Unit Step Signal');

n3 = -5:5;
r  = 0:5;
x3 = [zeros(1,5),r];
subplot(3,2,3);
stem(n3,x3);
xlabel('Time');
ylabel('Amplitude');
title('Unit Ramp Signal');

a1 = 0.8;
n4 = 0:1:100;
x4 = power(a1,n4);
subplot(3,2,4);
stem(n4,x4);
xlabel('Time');
ylabel('Amplitude');
title('Decreasing Exponential Signal');

a2 = 1.2;
n5 = 0:1:100;
x5 = power(a2,n5);
subplot(3,2,5);
stem(n5,x5);
xlabel('Time');
ylabel('Amplitude');
title('Increasing Exponential Signal');

a3 = 1;
n6 = 0:0.01:1;
f1 = 1;
x6 = a3 * sin(2*pi*f1*n6);
subplot(3,2,6);
stem(n6,x6);
xlabel('Time');
ylabel('Amplitude');
title('Sine Signal');

