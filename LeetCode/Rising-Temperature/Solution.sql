select W1.Id
from Weather as W1, Weather as W2
where W1.Date-1 = W2.Date and W1.Temperature> W2.Temperature