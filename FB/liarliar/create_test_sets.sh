for((i=0;i<19;i++))
do
	echo "DOING $i for the file 100k_$i"
	java LLTest 100000 $i > 100k_$i.ip
done
