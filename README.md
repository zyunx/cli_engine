cli_engine
==========

A engine for write cli(text mode) application, mainly for debug. 


cli engine life cycle :

     init -> output -> prompt -> input -> exit
             /  ^         ^        /         ^
            /    \         \      /           \
           /      +---------+----+             \
          /                                     \
         + --------------------------------------+
