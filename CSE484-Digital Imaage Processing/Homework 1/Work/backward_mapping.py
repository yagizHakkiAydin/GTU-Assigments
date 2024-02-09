import math

pixel = [0,0,0]




def invertAffineMatrix(affineMatrix):


    # Check if the affine matrix is invertible.
    
	determinant = affineMatrix[0][0]*(affineMatrix[1][1]*affineMatrix[2][2]-affineMatrix[2][1]*affineMatrix[1][2])- affineMatrix[0][1]*(affineMatrix[1][0]*affineMatrix[2][2]-affineMatrix[2][0]*affineMatrix[1][2])+affineMatrix[0][2]*(affineMatrix[1][0]*affineMatrix[2][1]-affineMatrix[2][0]*affineMatrix[1][1])




	c1 = affineMatrix[1][1] * affineMatrix[2][2] - affineMatrix[1][2] * affineMatrix[2][1]
	c2 = -(affineMatrix[1][0] * affineMatrix[2][2] - affineMatrix[2][0] * affineMatrix[1][2])
	c3 = affineMatrix[1][0] * affineMatrix[2][1] - affineMatrix[1][1] * affineMatrix[2][0]


	c4 = -(affineMatrix[0][1] * affineMatrix[2][2] - affineMatrix[0][2] * affineMatrix[2][1])
	c5 = affineMatrix[0][0] * affineMatrix[2][2] - affineMatrix[2][0] * affineMatrix[0][2]
	c6 = -(affineMatrix[0][0] * affineMatrix[2][1] - affineMatrix[2][0] * affineMatrix[0][1])


	c7 = affineMatrix[0][1] * affineMatrix[1][2] - affineMatrix[1][1] * affineMatrix[0][2]
	c8 = -(affineMatrix[0][0] * affineMatrix[1][2] - affineMatrix[1][0] * affineMatrix[0][2])
	c9 = affineMatrix[0][0] * affineMatrix[1][1] - affineMatrix[1][0] * affineMatrix[0][1]


	adjecency = [[c1,c4,c7],[c2,c5,c8],[c3,c6,c9]]


	inverseAffineMatrix = [[0,0,0],[0,0,0],[0,0,0]]



	if determinant == 0:
		raise ValueError("The affine matrix is not invertible.")


	for i in range(3):
		for j in range(3):
			inverseAffineMatrix[i][j] = adjecency[i][j]/determinant
	return inverseAffineMatrix


def getNewCoordinates( coordinates,affineMatrix ):
    # x     0 0 0
    # y     0 0 0
    # 1     0 0 0


    first_row = affineMatrix[0][0]*coordinates[0] + affineMatrix[0][1]*coordinates[1] + affineMatrix[0][2]*coordinates[2]
    sec_row = affineMatrix[1][0]*coordinates[0] + affineMatrix[1][1]*coordinates[1] + affineMatrix[1][2]*coordinates[2]
    third_row = affineMatrix[2][0]*coordinates[0] + affineMatrix[2][1]*coordinates[1] + affineMatrix[2][2]*coordinates[2]

    new_coordinates = [ first_row 
                        , sec_row 
                        , third_row ]

    return new_coordinates






def scaleImage( image , scale_factor ):


	scale_matrix = [[scale_factor, 0,0]
                    ,[0, scale_factor,0]
                    ,[0,0,1]]


	inverse_scale_matrix = invertAffineMatrix(scale_matrix)


	original_width = len(image[0])
	original_height = len(image)


	scaled_width = int(original_width * scale_matrix[0][0])		#Calculate width and height
	scaled_height = int(original_height * scale_matrix[1][1])	#of output image



	#Generate output image with black pixels
	new_image = []
	for y in range(scaled_height):
		temp_line = []
		for x in range(scaled_width):
			temp_line.append(pixel)

		new_image.append(temp_line)




	for y in range( scaled_height ):
		for x in range( scaled_width ):
			new_coordinates = getNewCoordinates([x,y,1],inverse_scale_matrix)

			new_x = int( new_coordinates[0] )
			new_y = int( new_coordinates[1] )

			#Get output pixel from input pixel
			new_image[y][x] = image[new_y][new_x]

	return new_image








def rotateImage( image , angle ):

	radian_degree = angle * math.pi / 180

	rotate_matrix = [[ math.cos(radian_degree) , -math.sin(radian_degree), 0 ],
                     [ math.sin(radian_degree) , math.cos(radian_degree) , 0 ],
                     [0,0,1]
                     ]

	original_width = len(image[0])
	original_height = len(image)

	#Width and height of output are calculated by calculating amount of spaces at x and y axis
	width_after_scale = int(original_width * math.cos(radian_degree) + original_height * math.sin(radian_degree) )
	height_after_scale = int(original_height * math.cos(radian_degree) + original_width * math.sin(radian_degree))

	#Output image is being initialized with black pixels
	new_image = []
	for y in range( height_after_scale ):
		temp_line = []
		for x in range( width_after_scale ):
			temp_line.append(pixel)

		new_image.append( temp_line )   




	for y in range( height_after_scale ):
		for x in range( -int(math.sin(radian_degree) * original_height) , width_after_scale - int(math.sin(radian_degree) * original_height) ):

			#Pixel coordinates are calculated by matrix multiplication
			new_coordinates = getNewCoordinates([x,y,1],invertAffineMatrix(rotate_matrix))
			new_x = int( new_coordinates[0] )
			new_y = int( new_coordinates[1] )

			#Get output pixel by using input pixel
			if original_width > new_x >= 0 and  original_height > new_y >= 0:
				new_image[y][x+int(math.sin(radian_degree) * original_height)] = image[new_y][new_x]

	return new_image






def horizontalShearImage( image , shear_factor ):


	shear_matrix = [[ 1,shear_factor,0],
                     [0,1,0],
                     [0,0,1]]




	original_width = len(image[0])
	original_height = len(image)

	# Calculate the output image dimensions
	height_after_scale = original_height
	width_after_scale = original_width+int(height_after_scale*shear_factor)



	#Initialize output image with black pixels
	new_image = []
	for y in range( height_after_scale ):
		temp_line = []
		for x in range( width_after_scale ):
			temp_line.append(pixel)

		new_image.append( temp_line )   

	#get inverse of shear_matrix
	inv_matrix = invertAffineMatrix(shear_matrix)


	for y in range(0, height_after_scale ):
		for x in range( 0 , width_after_scale + int(height_after_scale*shear_factor) ):

			#Pixel coordinates are calculated by matrix multiplication
			new_coordinates = getNewCoordinates([x,y,1],inv_matrix)
			new_x = int( new_coordinates[0] )
			new_y = int( new_coordinates[1] )


			#Get output pixel by using input pixel
			if original_width > new_x >= 0 and  original_height > new_y >= 0 and width_after_scale > x >= 0 and height_after_scale > y >= 0:
				new_image[y][x] = image[new_y][new_x]

	return new_image









def verticalShearImage( image , shear_factor ):


	shear_matrix = [[ 1,0,0],
                     [shear_factor,1,0],
                     [0,0,1]]




	original_width = len(image[0])
	original_height = len(image)

	width_after_scale = int(original_width)
	height_after_scale = original_height




	new_image = []

	for y in range( height_after_scale + int(width_after_scale*shear_factor) ):
		temp_line = []
		for x in range( width_after_scale ):
			temp_line.append(pixel)

		new_image.append( temp_line )   


	inv_matrix = invertAffineMatrix(shear_matrix)


	for y in range(0, height_after_scale + int(width_after_scale*shear_factor) ):
		for x in range( 0 , width_after_scale ):
			new_coordinates = getNewCoordinates([x,y,1],inv_matrix)

			new_x = int( new_coordinates[0] )
			new_y = int( new_coordinates[1] )



			if original_width > new_x >= 0 and  original_height > new_y >= 0:
				new_image[y][x] = image[new_y][new_x]

	return new_image







def zoomImage(image, zoom_factor):
    width = len(image[0])
    height = len(image)

    x_coordinate_of_zoomed_image = int((width / 2) - ((width / zoom_factor) / 2))
    y_coordinate_of_zoomed_image = int((height / 2) - ((height / zoom_factor) / 2))


    scaled_image = scaleImage(image,zoom_factor)



    new_image = []
    for y in range(height):
        temp_line = []
        for x in range(width):
            temp_line.append(pixel)
        new_image.append(temp_line)

    for y in range(height):
        for x in range(width):
            new_image[y][x] = scaled_image[y+y_coordinate_of_zoomed_image][x+x_coordinate_of_zoomed_image]

    return new_image




