A random ASCII character is received every 100ms. We need to find a sequence of "GLROX" characters. There can be other characters in between! Once found- call a Found function and wait for the sequence again, if not found then wait until this sequence is found. If a new character does not come in 2 seconds call Timeout function and wait for the whole "GLROX" again even if previously received part of the sequence. The Process function which is your entry point is called every 100ms.



Expected results:

|Input	             |   Output         |
| ------------------ | ---------------- | 
|GabfdbLbsfbdRbasgOX |	  TRUE          |
|AA4hfghdAAGLROX	   |   TRUE           |
|GLRObas832hXbasb	   | TRUE             |
|GLROobiapjso83basb	 | FALSE (no X)     |
|glroxbpoaijspoiasjdb|FALSE (lower case)|
|GLpboiasjdbpoijOX	 |    FALSE (no R)  |

While debugging and testing:

- The timeout of 2 seconds is very less and hence for testing purpose request you to increase the timeout to 8000 at line 150.
- As per the task inputs the software is ready to take inputs for every 100ms. Hence, the start time and end time is calculated in every cycle and then printed. 
