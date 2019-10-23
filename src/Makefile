
skabuffer: main.o
	g++ -o skabuffer main.o -L ../../sydevs/build -l SyDEVS-static

main.o: main.cpp building_sdp_processor.h building_sdp_buffer.h building_sdp_subscription_scheduler.h  building_ska_data_delivery.h skabuffer.h
	g++ -I../../sydevs/src/ -c main.cpp

clean:
	rm *.o skabuffer
