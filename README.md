# ship
A programming problem.

--Story--
The ship’s engine has ceased, and now begins the preparations of taking the ship to the harbor
for repairs. Luckily it’s a straight shot to the harbor. The bad news is that the journey is long.
There are several tugboats currently scattered throughout the ocean that can help move the
ship to the harbor, but they may have to go out of their way to assist, and taking your crippled
ship the full distance is going to be taxing on resources for any 1 particular tugboat.
The tugboats have made an agreement. The tugboats will
take the shortest path to the direct route that your ship will
travel. Once the tugboats are on the route the closest
tugboat to your ship will travel from its starting location on
your ship’s route to your ship’s current location. Then the
tugboat will tow your ship back to where the tugboat started
on your ship’s route. When your ship reaches that tugboat’s
starting location, the tugboat will stop towing your ship and
will move back to its original location. After which the
process will repeat with the next closest tugboat.
If multiple tugboats would arrive at the same location on the
ship’s route, then only the tugboat that is closest to the
location on the ship’s route would move to that location. If
multiple tugboats are the same distance from the location
on the ship’s route, then the tugboat with the
lexicographically earliest name would move to the route.
It is dangerous on the high seas, and you’re afraid that your ship may fall victim to pirates that
are pretending to be a valid tugboat. Your goal is to produce the names of the tugboats that will
tow your ship to the harbor in the order they tow so that your ship.

--Problem--
Given the current location of your broken ship, the location of the harbor, and a list of tugboats
with both their location and name, determine the number and order in which the tugboats will
tow your ship based on the behavior specified above.

--Input--
Input will begin with a line containing 4 integers, xs, ys, xh, and yh (-10^6 ≤ xs, ys, xh, yh ≤ 10^6),
representing the x and y coordinates of your ship and the x and y coordinates of the harbor
respectively. The following line will contain a single integer, n (1 ≤ n ≤ 500,000), representing
the number of tugboats. The following n lines will each contain a tugboat description (one per
line). The tugboat description will contain 2 integers, x and y (-10^6 ≤ x, y ≤ 10^6), representing
the x and y coordinates of the tugboat respectively, followed by a string, s, representing the
name of the tugboat. The name will contain only upper and lower case characters of which
there will be at most 20. There will be at least 1 tugboat at the location of the harbor. Your ship
does not start at the harbor.

--Output--
Output should begin with a number k, representing the number of tugboats that will tow your
broken ship. Following this should be k lines each containing a single name of a tugboat, the
full list comprise the list of the tugboats that will tow your ship in the order they tow your ship.

