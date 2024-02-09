import math



pixel = [0, 0, 0]
def getNewCoordinates( coordinates,affineMatrix ):

    first_row = affineMatrix[0][0]*coordinates[0] + affineMatrix[0][1]*coordinates[1] + affineMatrix[0][2]*coordinates[2]
    sec_row = affineMatrix[1][0]*coordinates[0] + affineMatrix[1][1]*coordinates[1] + affineMatrix[1][2]*coordinates[2]
    third_row = affineMatrix[2][0]*coordinates[0] + affineMatrix[2][1]*coordinates[1] + affineMatrix[2][2]*coordinates[2]

    new_coordinates = [ first_row 
                        ,sec_row 
                        ,third_row ]

    return new_coordinates





#Returns scaled image with forward mapping
def scaleImage( image , scale_factor ):


    #Scale matrix
    scale_matrix = [[scale_factor, 0,0]
                    ,[0, scale_factor,0]
                    ,[0,0,1]]


    original_width = len(image[0])  # Width and height of the input
    original_height = len(image)    # image are stored

    scaled_width = int(original_width * scale_matrix[0][0])   # Width and height of the output
    scaled_height = int(original_height * scale_matrix[1][1]) # image are calculated and stored


    new_image = [] #New image is initialized as empty list

    #New image is being initialized with black pixels
    for y in range(scaled_height):
        temp_line = []
        for x in range(scaled_width):
            temp_line.append(pixel)  #Black pixel appended

        new_image.append(temp_line)



    for y in range( original_height ):
        for x in range( original_width ):

            # #Scale matrix and input image pixel coordinates are multiplied,so new pixel coordinate found
            new_coordinates = getNewCoordinates([x,y,1],scale_matrix) 
            new_x = int( new_coordinates[0] )
            new_y = int( new_coordinates[1] )


            new_image[new_y][new_x] = image[y][x]

    return new_image #Return output












def rotateImage( image , angle ):

    radian_degree = angle * math.pi / 180 #Degree converted to radian

    #Rotate matrix is calculated
    rotate_matrix = [[ math.cos(radian_degree) , -math.sin(radian_degree), 0 ],
                     [ math.sin(radian_degree) , math.cos(radian_degree) , 0 ],
                     [0,0,1]
                     ]

    #Width and height of input image are stored                
    original_width = len(image[0])
    original_height = len(image)

    #Width and height of output are calculated by calculating amount of spaces at x and y axis
    width_after_rotate = int(original_width * math.cos(radian_degree) + original_height * math.sin(radian_degree) )
    height_after_rotate = int(original_height * math.cos(radian_degree) + original_width * math.sin(radian_degree))



    new_image = [] #New image is initialized as empty list

    #New image is being initialized with black pixels
    for y in range(height_after_rotate):
        temp_line = []
        for x in range(width_after_rotate):
            temp_line.append(pixel)  #Black pixel appended

        new_image.append(temp_line)


    for y in range( original_height ):
        for x in range( original_width ):

            #Pixel coordinates are calculated by matrix multiplication
            new_coordinates = getNewCoordinates([x,y,1],rotate_matrix)
            new_x = int( new_coordinates[0] )
            new_y = int( new_coordinates[1] )

            #Shifting image, so bottom-left corner stays in border of the frame
            new_x += int( math.sin(radian_degree) * original_height )

            #Set corresponding pixel
            new_image[new_y][new_x] = image[y][x]

    return new_image










def horizontalShearImage(image, shear_factor):

    shear_matrix = [[1, shear_factor,0]
                    ,[0, 1,0]
                    ,[0,0,1]]

    original_width = len(image[0])
    original_height = len(image)

    # Calculate the output image dimensions
    sheared_image_width = int(original_width + (original_height*shear_factor))
    sheared_height = int(original_height)



    #Initialize output image with black pixels
    new_image = []
    for y in range(sheared_height):
        temp_line = []
        for x in range(sheared_image_width):
            temp_line.append(pixel)
        new_image.append(temp_line)



    for y in range( original_height ):
        for x in range( original_width ):
            #Pixel coordinates are calculated by matrix multiplication
            new_coordinates = getNewCoordinates([x,y,1],shear_matrix)
            new_x = int( new_coordinates[0] )
            new_y = int( new_coordinates[1] )

            #Set corresponding pixel
            new_image[new_y][new_x] = image[y][x]

    return new_image





def verticalShearImage(image, shear_factor):

    shear_matrix = [[1, 0,0]
                    ,[shear_factor, 1,0]
                    ,[0,0,1]]

    original_width = len(image[0])
    original_height = len(image)

    # Calculate the sheard image dimensions
    sheared_width = int(original_width)
    sheared_height = int(original_height + (original_width*shear_factor)) 




    new_image = []

    for y in range(sheared_height):
        temp_line = []
        for x in range(sheared_width):
            temp_line.append(pixel)

        new_image.append(temp_line)




    for y in range( original_height ):
        for x in range( original_width ):
            new_coordinates = getNewCoordinates([x,y,1],shear_matrix)

            new_x = int( new_coordinates[0] )
            new_y = int( new_coordinates[1] )


            new_image[new_y][new_x] = image[y][x]

    return new_image







def zoomImage(image, zoom_factor):
    width = len(image[0])
    height = len(image)


    #finding x and y coordinates of the top left of scaled image's zoomed part
    x_coordinate_of_zoomed_image = int((width / 2) - ((width / zoom_factor) / 2))
    y_coordinate_of_zoomed_image = int((height / 2) - ((height / zoom_factor) / 2))


    scaled_image = scaleImage(image,zoom_factor)


    #new blank image with the same width and height with input
    new_image = []
    for y in range(height):
        temp_line = []
        for x in range(width):
            temp_line.append(pixel)
        new_image.append(temp_line)


    #copying middle part of the scaled image to new image
    for y in range(height):
        for x in range(width):
            new_image[y][x] = scaled_image[y+y_coordinate_of_zoomed_image][x+x_coordinate_of_zoomed_image]

    return new_image



