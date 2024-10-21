The forward kinematics analysis is the process of determining the posture of the end effector based on the known posture of each joint. 
The research of inverse kinematics is what posture each joint should be when the end effector reachs a certain position; 
That is to say, given the position and orientation of the end effector, calculate the angle of each joint.

The popular Denavit­ Hartenberg(D­H) incorporates too much matrix calculation, consuming too much resource and time.
Our code is based on a simplifed model for 4 robot arms.
Note that, trigonometric function and square root may not be practical in some embeded cpu so a dedicated math library should be implemented and carefull examination about the data type and operations should be done while coding, which is the very challenge for the SoC programming.

The formula derivation is as following:

$$
\begin{align}
x &= l_0\cos{\theta_1}+l_1\cos{(\theta_1+\theta_2)}+l_2\cos{(\theta_1+\theta_2+\theta_3)}\\
y &= l_0\sin{\theta_1}+l_1\sin{(\theta_1+\theta_2)}+l_2\sin{(\theta_1+\theta_2+\theta_3)}\\
\alpha &= \theta_1+\theta_2+\theta_3\\
\end{align}
$$

Then we have:

$$
\begin{align}
x &= l_0\cos{\theta_1}+l_1\cos{(\theta_1+\theta_2)}+l_2\cos{\alpha}\\
y &= l_0\sin{\theta_1}+l_1\sin{(\theta_1+\theta_2)}+l_2\sin{\alpha}\\
\end{align}
$$

supposing $m = l_2\cos{\alpha}-x, n = l_2\sin{\alpha}-y$,

$$
\begin{align}
l_1 &= (l_0\cos{\theta_1}+m)^2+(l_0\sin{\theta_1}+n)^2\\
\sin{\theta_1} &=(-b_1\pm \sqrt{b_1^2-4ac})/2a\\
\theta_1 &=\arcsin{[(-b_1\pm \sqrt{b_1^2-4ac})/2a]}\\
\end{align}
$$

where 

$$
\begin{align}
a &=m^2+n^2\\
b_1 &=-2nk_1\\
c &=k^2-m^2\\
k_1 &=(l_{1}^{2}-l_{0}^2-m^2-n^2)/2l_0\\
\end{align}
$$

The same as before:

$$
\sin{(\theta_1+\theta_2)}= \frac{-b_2\pm \sqrt{b_2^2-4ac}}{2a}
$$
