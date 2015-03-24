again="a"
until [ "$again" -eq  0 ] 
do
 	./TestDeatSad > out
 	./deatSad < out > dout
      	

	echo $again


done