CC = g++
FLAGS = -std=c++11
LIBS = -I lib/Eigen
OBJECTS = lib/assignment.o lib/curve.o lib/curve_ops.o lib/distance_ops.o lib/distance_f.o lib/general_hash.o lib/hash_f.o lib/hashtable_init.o lib/initialization.o lib/lsh.o lib/mean_curves.o lib/minmax.o lib/rand_utils.o lib/range_assign.o lib/silhouette.o lib/update.o Proteins/mainp.o Proteins/pr_data_ops.o Roads/ro_data_ops.o Roads/road.o Roads/xml_ops.o Roads/mainr.o

PROTOBJECTS = Proteins/mainp.o Proteins/pr_data_ops.o lib/assignment.o lib/curve.o lib/distance_ops.o lib/distance_f.o lib/initialization.o lib/mean_curves.o lib/minmax.o lib/rand_utils.o lib/silhouette.o lib/update.o

ROADOBJECTS = lib/curve.cpp lib/curve_ops.o lib/range_assign.o lib/assignment.cpp lib/hashtable_init.o lib/initialization.cpp lib/general_hash.o lib/hash_f.o lib/lsh.o lib/update.cpp lib/silhouette.cpp lib/distance_f.cpp lib/rand_utils.cpp lib/minmax.cpp lib/distance_ops.cpp lib/mean_curves.cpp Roads/ro_data_ops.o Roads/road.o Roads/xml_ops.o Roads/mainr.o

pr : mainp

rd : mainr

mainp : $(PROTOBJECTS)
	$(CC) $(FLAGS) $(LIBS) -o prot $(PROTOBJECTS)

mainr : $(ROADOBJECTS)
	$(CC) $(FLAGS) $(LIBS) -o ways $(ROADOBJECTS)

lib/assignment.o : lib/assignment.cpp
	$(CC) $(FLAGS) -c lib/assignment.cpp -o lib/assignment.o

lib/curve.o : lib/curve.cpp
	$(CC) $(FLAGS) -c lib/curve.cpp -o lib/curve.o

lib/curve_ops.o : lib/curve_ops.cpp
	$(CC) $(FLAGS) -c lib/curve_ops.cpp -o lib/curve_ops.o

lib/data_ops.o : lib/data_ops.cpp
	$(CC) $(FLAGS) -c lib/data_ops.cpp -o lib/data_ops.o

lib/distance_ops.o : lib/distance_ops.cpp
	$(CC) $(FLAGS) -c lib/distance_ops.cpp -o lib/distance_ops.o

lib/distance_f.o : lib/distance_f.cpp
	$(CC) $(FLAGS) -c lib/distance_f.cpp -o lib/distance_f.o

lib/general_hash.o : lib/general_hash.cpp
	$(CC) $(FLAGS) -c lib/general_hash.cpp -o lib/general_hash.o

lib/hash_f.o : lib/hash_f.cpp
	$(CC) $(FLAGS) -c lib/hash_f.cpp -o lib/hash_f.o

lib/hashtable_init.o : lib/hashtable_init.cpp
	$(CC) $(FLAGS) -c lib/hashtable_init.cpp -o lib/hashtable_init.o

lib/initialization.o : lib/initialization.cpp
	$(CC) $(FLAGS) -c lib/initialization.cpp -o lib/initialization.o

lib/lsh.o : lib/lsh.cpp
	$(CC) $(FLAGS) -c lib/lsh.cpp -o lib/lsh.o

lib/mean_curves.o : lib/mean_curves.cpp
	$(CC) $(FLAGS) -c lib/mean_curves.cpp -o lib/mean_curves.o

lib/minmax.o : lib/minmax.cpp
	$(CC) $(FLAGS) -c lib/minmax.cpp -o lib/minmax.o

lib/rand_utils.o : lib/rand_utils.cpp
	$(CC) $(FLAGS) -c lib/rand_utils.cpp -o lib/rand_utils.o

lib/range_assign.o : lib/range_assign.cpp
	$(CC) $(FLAGS) -c lib/range_assign.cpp -o lib/range_assign.o

lib/silhouette.o : lib/silhouette.cpp
	$(CC) $(FLAGS) -c lib/silhouette.cpp -o lib/silhouette.o

lib/update.o :lib/update.cpp
	$(CC) $(FLAGS) -c lib/update.cpp -o lib/update.o

Proteins/mainp.o : Proteins/mainp.cpp
	$(CC) $(FLAGS) -c Proteins/mainp.cpp -o Proteins/mainp.o

Proteins/pr_data_ops.o : Proteins/pr_data_ops.cpp
	$(CC) $(FLAGS) -c Proteins/pr_data_ops.cpp -o Proteins/pr_data_ops.o

Roads/ro_data_ops.o : Roads/ro_data_ops.cpp
	$(CC) $(FLAGS) -c Roads/ro_data_ops.cpp -o Roads/ro_data_ops.o


Roads/road.o : Roads/road.cpp
	$(CC) $(FLAGS) -c Roads/road.cpp -o Roads/road.o

Roads/xml_ops.o : Roads/xml_ops.cpp
	$(CC) $(FLAGS) -c Roads/xml_ops.cpp -o Roads/xml_ops.o

Roads/mainr.o : Roads/mainr.cpp
	$(CC) $(FLAGS) -c Roads/mainr.cpp -o Roads/mainr.o

.PHONY : clean
clean :
	rm $(OBJECTS) prot ways
