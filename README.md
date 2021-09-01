# PID Controller

A PID controller was optimized to drive the car in the simulation.
Due to the nature of the simulator, I couldn't use twiddle or other
optimization techniques as you have to run the simulator manually for each trial.

I choose to tweak the parameters manually given the
following intuition:

Kp (p parameter) is proportional to the amount
of time the system takes to approach the goal value, although increasing it too
much produces overshoots.

Ki ( I parameter) help reducing
steady state error but may produce overshoots as it is accumulative by
definition. My tweeking showed this parameter as the
most sensitive specially after curves as the accumulative cte
tends to get bigger and bigger.

Kd ( d parameter) helps smoothing the control response
and hence provides smooth driving but too much value can increase error.

## How did I tweak the parameters?

Started by configuring the main function to accept arguments
as advised for faster trials without further builds. I also used simple if
statement to limit throttle when cte is large and
when car has a relatively large cte in addition to (high)
speed.

Started with Kp = 0->-0.5 and other parameters set to 0. Found that 0.5 is a starting good value.
Choose Kd=-0.6 and that stabilized driving as a first start.

Started trials with Ki and found it very sensitive and can easily produce overshoots, set it to lower value till I reached .006

Simulation went relatively well and I used a debugging output that listed P,I and D values separately. During the curves, the response was relatively slow by the P and then the I part begins to grow due to accumulation and produces overshoots.

Added 5-10% to P and D components each trial, sometimes
separately and sometimes in parallel and decrease the I value 10% separately. The
following produced best results

./pid -0.11 -.0003 -1.1</b>

i.e, Kp=-0.11, Ki=-.0003 and Kd=-1.1

## References:

https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/16311/www/s16/syllabus/ppp/Lec05-Control1.pdf
