/*
 * ImageConverter.cpp declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Created: March 2015
 *  Revised: November 2016
 *  Revised for TSGL-2: November 2020
 */

#include "ImageConverter.h"
#include <unistd.h>            // sleep()

//-----------------  Method definitions ------------------------------

/* explicit constructor
 *
 * @param imageFileName, a string.
 * @param width, an int.
 * @param height, an int.
 *
 * Precondition: imageFileName contains the name of a valid image file
 *               && width > 0 && height > 0
 * Postcondition: myImageFileName == imageFileName
 *                && myWidth == width && myHeight = height
 *                && a width x height Canvas containing the image
 *                    from imageFileName has been displayed on screen
 *                && a blank width x height Canvas as also been displayed.
 */
ImageConverter::ImageConverter(const std::string& imageFileName, 
		                int width, int height)
 :
   myCanvas0(0, 0, width, height, imageFileName),
   myWidth(width),
   myHeight(height),
   myImageFileName(imageFileName)
{
    myCanvas0.start();
    myCanvas0.getBackground()->drawImage(0, 0, 0, imageFileName, 
                                          width, height, 0, 0, 0);
}

/* destructor
 *
 * Precondition: this ImageConverter object is going out of scope.
 * Postcondition: a "normal termnation" message has been displayed.
 */
ImageConverter::~ImageConverter() {
    cout << "\nImageConverter terminated normally." << endl;
}

/* method to run image-conversion methods
 * PostCondition: the converted version of the image from myCanvas0
 *                 has been displayed in a new Canvas
 *               && myCanvas0 has been closed.
 */
void ImageConverter::run() {
    // invertImage();
    myCanvas0.wait();
}	


/* invertImage() inverts the image from myImageFileName.
 *
 * Precondition: myCanvas0 contains a TSGL Image that is to be inverted
 *            && myWidth == the number of columns in which to display the image
 *            && myHeight == the number of rows in which to display the image.
 *
 * Postcondition: a myWidth x myHeight Canvas has been displayed
 *                 containing the inverse of the image from myCanvas0
 *                 (which contains the image from myImageFileName).
 */

// Replace this line with the definition of invertImage()

