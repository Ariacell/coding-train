My answers to the various challenge questions found on protohackers.com

Building (needs rapidjson since I will potentially use this professionally and want to incorporate it)
Should be mostly compatible crossplatform, but deliberately forcing myself to develop on Windows for these to improve my knowledge of non-Unix systems.

Windows
```sh
g++ -Wall -Werror -I../vendor/rapidjson/include *.h main.cpp -o main.exe -static -lws2_32
g++ -Wall -Werror -I../vendor/rapidjson/include *.h client.cpp -o client.exe -static -lws2_32
```

Spinning up servers can be done via the exes produced above, or simply curl the server with a cheeky .9http for now until I gt farther in the exercises and add proper headers etc to the server response:
```
curl --http0.9 -X POST localhost:12345 -d "{"blah":123}"
```