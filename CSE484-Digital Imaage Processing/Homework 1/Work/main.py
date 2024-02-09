import cv2
import numpy as np
import forward_mapping
import backward_mapping
import backward_mapping_w_interpolation


#Read image
image = cv2.imread("istanbul.jpg")


#Converting image to python list to pass the functions
image = image.tolist()


#In this section,images are sent to transform functions
#Outputs of those functions are stored in numpy arrays
istanbul_scaled_forward_mapping = forward_mapping.scaleImage(image,1.5) 					#
istanbul_scaled_backward_mapping = backward_mapping.scaleImage(image,1.5) 					#scale
i_istanbul_scaled_backward_mapping = backward_mapping_w_interpolation.scaleImage(image,1.5) #


istanbul_rotated_forward_mapping = forward_mapping.rotateImage(image,30)						#
istanbul_rotated_backward_mapping = backward_mapping.rotateImage(image,30)						#rotate
i_istanbul_rotated_backward_mapping = backward_mapping_w_interpolation.rotateImage(image,30)	#


istanbul_vertical_chear_forward_mapping = forward_mapping.verticalShearImage(image,0.3) 				   #
istanbul_vertical_chear_backward_mapping = backward_mapping.verticalShearImage(image,0.3) 				   #vertical shear
i_istanbul_vertical_chear_forward_mapping = backward_mapping_w_interpolation.verticalShearImage(image,0.3) #


istanbul_horizontal_shear_forward_mapping = forward_mapping.horizontalShearImage(image,0.3) 					#
istanbul_horizontal_shear_backward_mapping = backward_mapping.horizontalShearImage(image,0.3) 					#horizontal shear
i_istanbul_horizontal_shear_backward_mapping = backward_mapping_w_interpolation.horizontalShearImage(image,0.3) #


istanbul_zoomed_forward_mapping = forward_mapping.zoomImage(image,1.6) 					   #
istanbul_zoomed_backward_mapping = backward_mapping.zoomImage(image,1.6) 				   #zoom
i_istanbul_zoomed_backward_mapping = backward_mapping_w_interpolation.zoomImage(image,1.6) #









#Converting lists back to numpy arrays

istanbul_scaled_forward_mapping = np.array(istanbul_scaled_forward_mapping , dtype=np.uint8)
istanbul_scaled_backward_mapping = np.array(istanbul_scaled_backward_mapping , dtype=np.uint8)
i_istanbul_scaled_backward_mapping = np.array(i_istanbul_scaled_backward_mapping , dtype=np.uint8)

istanbul_rotated_forward_mapping = np.array(istanbul_rotated_forward_mapping , dtype=np.uint8)
istanbul_rotated_backward_mapping = np.array(istanbul_rotated_backward_mapping , dtype=np.uint8)
i_istanbul_rotated_backward_mapping = np.array(i_istanbul_rotated_backward_mapping , dtype=np.uint8)

istanbul_vertical_chear_forward_mapping = np.array(istanbul_vertical_chear_forward_mapping , dtype=np.uint8)
istanbul_vertical_chear_backward_mapping = np.array(istanbul_vertical_chear_backward_mapping , dtype=np.uint8)
i_istanbul_vertical_chear_forward_mapping = np.array(i_istanbul_vertical_chear_forward_mapping , dtype=np.uint8)

istanbul_horizontal_shear_forward_mapping = np.array(istanbul_horizontal_shear_forward_mapping , dtype=np.uint8)
istanbul_horizontal_shear_backward_mapping = np.array(istanbul_horizontal_shear_backward_mapping , dtype=np.uint8)
i_istanbul_horizontal_shear_backward_mapping = np.array(i_istanbul_horizontal_shear_backward_mapping , dtype=np.uint8)

istanbul_zoomed_forward_mapping = np.array(istanbul_zoomed_forward_mapping , dtype=np.uint8)
istanbul_zoomed_backward_mapping = np.array(istanbul_zoomed_backward_mapping , dtype=np.uint8)
i_istanbul_zoomed_backward_mapping = np.array(i_istanbul_zoomed_backward_mapping , dtype=np.uint8)



#Writing results to "/results" folder
cv2.imwrite("results/forward_mapping/stanbul_scaled_forward_mapping.jpg", istanbul_scaled_forward_mapping)
cv2.imwrite("results/backward_mapping/istanbul_scaled_backward_mapping.jpg", istanbul_scaled_backward_mapping)
cv2.imwrite("results/backward_with_interpolation/i_istanbul_scaled_backward_mapping.jpg", i_istanbul_scaled_backward_mapping)

cv2.imwrite("results/forward_mapping/istanbul_rotated_forward_mapping.jpg", istanbul_rotated_forward_mapping)
cv2.imwrite("results/backward_mapping/istanbul_rotated_backward_mapping.jpg", istanbul_rotated_backward_mapping)
cv2.imwrite("results/backward_with_interpolation/i_istanbul_rotated_backward_mapping.jpg", i_istanbul_rotated_backward_mapping)

cv2.imwrite("results/forward_mapping/istanbul_vertical_chear_forward_mapping.jpg", istanbul_vertical_chear_forward_mapping)
cv2.imwrite("results/backward_mapping/istanbul_vertical_chear_backward_mapping.jpg", istanbul_vertical_chear_backward_mapping)
cv2.imwrite("results/backward_with_interpolation/i_istanbul_vertical_chear_forward_mapping.jpg", i_istanbul_vertical_chear_forward_mapping)

cv2.imwrite("results/forward_mapping/istanbul_horizontal_shear_forward_mapping.jpg", istanbul_horizontal_shear_forward_mapping) 
cv2.imwrite("results/backward_mapping/istanbul_horizontal_shear_backward_mapping.jpg", istanbul_horizontal_shear_backward_mapping) 
cv2.imwrite("results/backward_with_interpolation/i_istanbul_horizontal_shear_backward_mapping.jpg", i_istanbul_horizontal_shear_backward_mapping) 

cv2.imwrite("results/forward_mapping/istanbul_zoomed_forward_mapping.jpg", istanbul_zoomed_forward_mapping) 
cv2.imwrite("results/backward_mapping/istanbul_zoomed_backward_mapping.jpg", istanbul_zoomed_backward_mapping) 
cv2.imwrite("results/backward_with_interpolation/i_istanbul_zoomed_backward_mapping.jpg", i_istanbul_zoomed_backward_mapping) 










