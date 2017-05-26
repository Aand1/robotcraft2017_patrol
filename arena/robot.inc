define stopy_robot position(

    size [0.6 0.56 0.3]
    origin [0 0 0 0]
    gui_nose 1
    obstacle_return 1
    ranger_return 1
    drive "diff"
    
    
    
    

    # base rectangular shape of the Stop robot
    block( points 4
        point[0] [ 0.3 0.27 ]
        point[1] [ -0.3 0.27 ]
        point[2] [ -0.3 -0.27 ]
        point[3] [ 0.3 -0.27 ]
        z [0.12 0.15]
    )
    
    
    
    
    #front left pole
    block( points 4
        point[0] [ 0.3 0.27 ]
        point[1] [ 0.25 0.27 ]
        point[2] [ 0.25 0.22 ]
        point[3] [ 0.3 0.22]
        z [0.15 0.27]
    )
    
    #front right pole
    block( points 4
        point[0] [ 0.3 -0.22 ]
        point[1] [ 0.25 -0.22 ]
        point[2] [ 0.25 -0.27 ]
        point[3] [ 0.3 -0.27 ]
        z [0.15 0.27]
    )    
    
    #back left pole
    block( points 4
        point[0] [ -0.25 -0.22 ]
        point[1] [ -0.3 -0.22 ]
        point[2] [ -0.3 -0.27 ]
        point[3] [ -0.25 -0.27 ]
        z [0.15 0.27]
    )    
    
    #back right pole
    block( points 4
        point[0] [ -0.25 0.27 ]
        point[1] [ -0.3 0.27 ]
        point[2] [ -0.3 0.22 ]
        point[3] [ -0.25 0.22 ]
        z [0.15 0.27]
    )   
    
    
    
    
    
    #top left structure
    block( points 4
        point[0] [ 0.3 0.27 ]
        point[1] [ -0.3 0.27 ]
        point[2] [ -0.27 0.24 ]
        point[3] [ 0.27 0.24 ]
        z [0.27 0.3]
    )    
    
    #top back structure
    block( points 4
        point[0] [ -0.27 0.27 ]
        point[1] [ -0.3 0.27 ]
        point[2] [ -0.3 -0.27 ]
        point[3] [ -0.27 -0.27 ]
        z [0.27 0.3]
    )  
    
    #top right structure
    block( points 4
        point[0] [ -0.3 -0.27 ]
        point[1] [ 0.3 -0.27 ]
        point[2] [ 0.3 -0.24 ]
        point[3] [ -0.3 -0.24 ]
        z [0.27 0.3]
    )      
    
    #top front structure
    block( points 4
        point[0] [ 0.3 0.27 ]
        point[1] [ 0.27 0.27 ]
        point[2] [ 0.27 -0.27 ]
        point[3] [ 0.3 -0.27 ]
        z [0.27 0.3]
    )     
    
    
    
    
    
    #right wheel
    block(     
        color "black"
        points 4
        point[0] [ -0.03 -0.28 ]
        point[1] [ 0.03 -0.28 ]
        point[2] [ 0.03 -0.22 ]
        point[3] [ -0.03 -0.22 ]
        z [0.0 0.145]
    )     
    
    #right wheel left piece 1
    block(     
        color "black"
        points 4
        point[0] [ -0.05125 -0.28 ]
        point[1] [ -0.03 -0.28 ]
        point[2] [ -0.03 -0.22 ]
        point[3] [ -0.05125 -0.22 ]
        z [0.02125 0.12375]
    )      
    
    #right wheel left piece 2
    block(     
        color "black"
        points 4
        point[0] [ -0.0725 -0.28 ]
        point[1] [ -0.05125 -0.28 ]
        point[2] [ -0.05125 -0.22 ]
        point[3] [ -0.0725 -0.22 ]
        z [0.0425 0.1025]
    )       
    
    #right wheel right piece 1
    block(     
        color "black"
        points 4
        point[0] [ 0.03 -0.28 ]
        point[1] [ 0.05125 -0.28 ]
        point[2] [ 0.05125 -0.22 ]
        point[3] [ 0.03 -0.22 ]
        z [0.02125 0.12375]
    )    
    
    #right wheel right piece 2
    block(     
        color "black"
        points 4
        point[0] [ 0.05125 -0.28 ]
        point[1] [ 0.0725 -0.28 ]
        point[2] [ 0.0725 -0.22 ]
        point[3] [ 0.05125 -0.22 ]
        z [0.0425 0.1025]
    )       
    
    
    
    
    
    #left wheel 
    block(     
        color "black"
        points 4
        point[0] [ -0.03 0.22 ]
        point[1] [ 0.03 0.22 ]
        point[2] [ 0.03 0.28 ]
        point[3] [ -0.03 0.28 ]
        z [0.0 0.145]
    )      
    
    #left wheel left piece 1
    block(     
        color "black"
        points 4
        point[0] [ -0.05125 0.22 ]
        point[1] [ -0.03 0.22 ]
        point[2] [ -0.03 0.28 ]
        point[3] [ -0.05125 0.28 ]
        z [0.02125 0.12375]
    )      
    
    #left wheel left piece 2
    block(     
        color "black"
        points 4
        point[0] [ -0.0725 0.22 ]
        point[1] [ -0.05125 0.22 ]
        point[2] [ -0.05125 0.28 ]
        point[3] [ -0.0725 0.28 ]
        z [0.0425 0.1025]
    )   
    
    #right wheel left piece 1
    block(     
        color "black"
        points 4
        point[0] [ 0.03 0.22 ]
        point[1] [ 0.05125 0.22 ]
        point[2] [ 0.05125 0.28 ]
        point[3] [ 0.03 0.28 ]
        z [0.02125 0.12375]
    )    
    
    #right wheel left piece 2
    block(     
        color "black"
        points 4
        point[0] [ 0.05125 0.22 ]
        point[1] [ 0.0725 0.22 ]
        point[2] [ 0.0725 0.28 ]
        point[3] [ 0.05125 0.28 ]
        z [0.0425 0.1025]
    )      
    
    
    
    
    
    #front wheel
    block(     
        color "gray"
        points 4
        point[0] [ 0.16 -0.02 ]
        point[1] [ 0.20 -0.02 ]
        point[2] [ 0.20 0.02 ]
        point[3] [ 0.16 0.02 ]
        z [0.0 0.12]
    )  
    
    #front wheel left piece 1
    block(     
        color "gray"
        points 4
        point[0] [ 0.14 -0.02 ]
        point[1] [ 0.16 -0.02 ]
        point[2] [ 0.16 0.02 ]
        point[3] [ 0.14 0.02 ]
        z [0.02 0.1]
    )  
    
   #front wheel left piece 2
    block(     
        color "gray"
        points 4
        point[0] [ 0.12 -0.02 ]
        point[1] [ 0.14 -0.02 ]
        point[2] [ 0.14 0.02 ]
        point[3] [ 0.12 0.02 ]
        z [0.04 0.08]
    )    
    
    #front wheel right piece 1
    block(     
        color "gray"
        points 4
        point[0] [ 0.20 -0.02 ]
        point[1] [ 0.22 -0.02 ]
        point[2] [ 0.22 0.02 ]
        point[3] [ 0.20 0.02 ]
        z [0.02 0.1]
    )  
    
   #front wheel right piece 2
    block(     
        color "gray"
        points 4
        point[0] [ 0.22 -0.02 ]
        point[1] [ 0.24 -0.02 ]
        point[2] [ 0.24 0.02 ]
        point[3] [ 0.22 0.02 ]
        z [0.04 0.08]
    ) 
    
    
    
    
    
    #back wheel
    block(     
        color "gray"
        points 4
        point[0] [ -0.2 -0.02 ]
        point[1] [ -0.16 -0.02 ]
        point[2] [ -0.16 0.02 ]
        point[3] [ -0.2 0.02 ]
        z [0.0 0.12]
    )  
    
    #back wheel left piece 1
    block(     
        color "gray"
        points 4
        point[0] [ -0.16 -0.02 ]
        point[1] [ -0.14 -0.02 ]
        point[2] [ -0.14 0.02 ]
        point[3] [ -0.16 0.02 ]
        z [0.02 0.1]
    )  
    
    #back wheel left piece 2
    block(     
        color "gray"
        points 4
        point[0] [ -0.14 -0.02 ]
        point[1] [ -0.12 -0.02 ]
        point[2] [ -0.12 0.02 ]
        point[3] [ -0.14 0.02 ]
        z [0.04 0.08]
    )       
    
    #back wheel right piece 1
    block(     
        color "gray"
        points 4
        point[0] [ -0.22 -0.02 ]
        point[1] [ -0.2 -0.02 ]
        point[2] [ -0.2 0.02 ]
        point[3] [ -0.22 0.02 ]
        z [0.02 0.1]
    )  
    
   #back wheel right piece 2
    block(     
        color "gray"
        points 4
        point[0] [ -0.24 -0.02 ]
        point[1] [ -0.22 -0.02 ]
        point[2] [ -0.22 0.02 ]
        point[3] [ -0.24 0.02 ]
        z [0.04 0.08]
    )     
    
    
    
    
    rplidar( pose [0 0 -0.14 0] )

    # Some more realistic localization error
    localization "odom"
    odom_error [ 0.03 0.03 0.0 4 ]
)