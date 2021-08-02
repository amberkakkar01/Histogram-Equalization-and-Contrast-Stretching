#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Check_image(FILE *file);
void ComputeHistogram(unsigned char *buffer,int *hist1, int w,int h);
void Equalize(unsigned char *buffer, int *hist1, int w,int h);
void HistogramComparison(unsigned char *buffer1, unsigned char *buffer3, int *hist1,int *hist3, int w,int h);
void HistogramMatching(unsigned char *buffer2, int *hist2,unsigned char *buffer3, int *hist3, int *hist_match, int w,int h);

int main()
{
    /*Arrays to store histogram data*/
    int hist1[256] = {0}, hist2[256] = {0}, hist_match[256] = {0}, hist3[256] = {0};

    /*Pointers used to read in image data*/
    FILE *fptr1, *fptr2, *fptr3;

    /*Storing the image dimensions*/
    int h, w, sz;
    int i, j, opt;

    /*Storing the image file paths*/
    char fname1[1000], fname2[1000], fname3[1000];

    /*Switch case statement for selecting an image histogram operation*/
    while(1)
    {
        printf("\nImage Histogram Operations:\n1. Histogram of image\n");
        printf("2. Histogram Equalization\n3. Histogram Comparison\n4. Histogram Matching\n5. EXIT\n");

        printf("\nEnter your choice: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
            /*Reading and processing image for histogram equalization*/
            printf("Enter file path for the image: ");
            scanf("%s", fname1);

            /*Reading in image dimensions*/
            printf("Enter image width: ");
            scanf("%d", &w);
            printf("Enter image height: ");
            scanf("%d", &h);
            sz = h*w;

            /*Memory allocation for image data storage buffer*/
            unsigned char *buffer1 = (unsigned char*) calloc(sz, sizeof(unsigned char));

            /*Reading and storing the image data in array*/
            fptr1 = fopen(fname1, "rb");
            fread(buffer1, sz*sizeof(unsigned char), 1, fptr1);

            /*Function computes and displays histogram as pixel intensity counts*/
            ComputeHistogram(buffer1, hist1, w, h);
            /*Displaying histogram as pixel intensity counts*/
            for(i = 0;  i < 256; i++)
                printf("Histogram counts for pixel intensity levels %d = %d\n", i, hist1[i]);

            if(Check_image(fptr1)==1)
                printf("\n\nERROR : ENTER VALID FILE PATH!");

            fclose(fptr1);
            break;
        case 2:
            /*Reading and processing the image for equalization*/
            printf("Enter file path for the image: ");
            scanf("%s", fname1);
            /*Reading in image dimensions*/
            printf("Enter image width: ");
            scanf("%d", &w);
            printf("Enter image height: ");
            scanf("%d", &h);
            sz = h*w;

            /*Memory allocation for image data storage buffer*/
            unsigned char *buffer2 = (unsigned char*) calloc(sz, sizeof(unsigned char));

            fptr1 = fopen(fname1, "rb");
            /*Storing the image data in array*/
            fread(buffer2, sz*sizeof(unsigned char), 1, fptr1);

            /*Function equalizes an image using its Histogram*/
            Equalize(buffer2, hist1, w, h);
            printf("\n\nHistogram counts for pixel intensity levels of the equalized image:\n\n");

            for(i = 0; i < 256; i++)
                printf("Histogram counts for pixel intensity levels %d = %d\n", i, 	hist1[i]);

            /*Saving the equalized image*/
            printf("\n\nEnter file path for saving the equalized image:");
            printf("\nCAUTION : DO NOT OVERWRITE ANY IMPORTANT 	DATA!\n");
            printf("Enter file path: ");
            scanf("%s", fname2);
            fptr2 = fopen(fname2, "wb");
            fwrite(buffer2, sz*sizeof(unsigned char), 1, fptr2);

            if(Check_image(fptr1)==1)
                printf("\n\nERROR : ENTER VALID FILE PATH!");

            fclose(fptr1);
            fclose(fptr2);
            break;
        case 3:
            /*Reading in and processing the first image*/

            printf("Enter file path for the first image: ");
            scanf("%s", fname1);

            /*Reading in image dimensions*/
            printf("Enter image width: ");
            scanf("%d", &w);
            printf("Enter image height: ");
            scanf("%d", &h);
            sz = h*w;

            /*Memory allocation for image data storage buffer*/
            unsigned char *buffer3 = (unsigned char*) calloc(sz, sizeof(unsigned char));

            /*Reading and storing the image data in array*/
            fptr1 = fopen(fname1, "rb");
            fread(buffer3, sz*sizeof(unsigned char), 1, fptr1);

            /*Reading in and processing the second image*/

            printf("Enter file path for the second image: ");
            scanf("%s", fname2);

            /*Reading in image dimensions*/
            printf("Enter image width: ");
            scanf("%d", &w);
            printf("Enter image height: ");
            scanf("%d", &h);
            sz = h*w;

            /*Memory allocation for image data storage buffer*/
            unsigned char *buffer4 = (unsigned char*) calloc(sz, sizeof(unsigned char));

            /*Reading and storing the image data in array*/
            fptr2 = fopen(fname2, "rb");
            fread(buffer4, sz*sizeof(unsigned char), 1, fptr2);

            /*Compares the histograms of two images using intersection metric*/
            HistogramComparison(buffer3, buffer4, hist1, hist3, w, h);

            if(Check_image(fptr1)==1)
                printf("\n\nERROR : ENTER VALID FILE PATH FOR THE 	FIRST IMAGE!");

            if(Check_image(fptr2)==1)
                printf("\n\nERROR : ENTER VALID FILE PATH FOR THE 	SECOND IMAGE!");

            fclose(fptr1);
            fclose(fptr2);
            break;
        case 4:
            /*Reading in and processing the first image*/

            printf("Enter file path for the first image: ");
            scanf("%s", fname1);
            /*Reading in image dimensions*/
            printf("Enter image width: ");
            scanf("%d", &w);
            printf("Enter image height: ");
            scanf("%d", &h);
            sz = h*w;

            /*Memory allocation for image data storage buffer*/
            unsigned char *buffer5 = (unsigned char*) calloc(sz, sizeof(unsigned char));

            /*Reading and storing the image data in array*/
            fptr1 = fopen(fname1,"rb");
            fread(buffer5, sz*sizeof(unsigned char), 1, fptr1);

            /*Reading in and processing the second image*/

            printf("Enter file path for the second image: ");
            scanf("%s", fname2);

            /*Reading in image dimensions*/
            printf("Enter image width: ");
            scanf("%d", &w);
            printf("Enter image height: ");
            scanf("%d", &h);
            sz = h*w;

            /*Memory allocation for image data storage buffer*/
            unsigned char *buffer6 = (unsigned char*) calloc(sz, sizeof(unsigned char));

            /*Reading and storing the image data in array*/
            fptr2 = fopen(fname2, "rb");
            fread(buffer6, sz*sizeof(unsigned char), 1, fptr2);

            HistogramMatching(buffer5, hist2, buffer6, hist3, hist_match, w, h);

            printf("\n\nHistogram counts for pixel intensity levels of the matched image:\n\n");
            for(i = 0; i < 256; i++)
                printf("Histogram count for pixel intensity level %d = %d\n", i, hist_match[i]);

            /*Saving the matched image*/
            printf("\n\nEnter file path for saving the matched image:");
            printf("\nCAUTION : DO NOT OVERWRITE ANY IMPORTANT 	FILE!\n");
            printf("Enter file path: ");
            scanf("%s", fname3);
            fptr3 = fopen(fname3, "wb");
            fwrite(buffer5, sz*sizeof(unsigned char), 1, fptr3);

            if(Check_image(fptr1)==1)
                printf("\n\nERROR : ENTER VALID FILE PATH FOR THE FIRST IMAGE!");
            if(Check_image(fptr2)==1)
                printf("\n\nERROR : ENTER VALID FILE PATH FOR THE 	SECOND IMAGE!");

            fclose(fptr1);
            fclose(fptr2);
            fclose(fptr3);
            break;
        case 5:
            return 0;
        default:
            /*Error message on invalid selection*/
            printf("Please select options from 1 to 5 only!\n");
        }
    }
    return 0;
}

/*This function checks the image file.*/
int Check_image(
		    FILE *file /*Pointer to the input file*/
		    )
{
    if(file == NULL)
        return 1;
    return 0;
}

/*This function computes the image histogram.*/
void ComputeHistogram(
		      	    unsigned char *buffer, /*Pointer to the image data array*/
		      	    int *hist1, /*Pointer to the image histogram array*/
		      	    int w, /*Variable holding image width*/
		      	    int h /*Variable holding image height*/
		      	    )
{
    int i, j;
    int sz = h*w;

    /*Initializing intensity level counts as zero*/
    for(i = 0; i < 256; i++)
        hist1[i] = 0;

    /*Computing histogram by counting the number of occurrences for each intensity level*/
    for(i = 0; i < sz; i++)
        hist1[buffer[i]] += 1;
}

/*This function equalizes the image histogram.*/
void Equalize(
		unsigned char *buffer, /*Pointer to the image data array*/
		int *hist1, /*Pointer to the image histogram array*/
		int w, /*Variable holding image width*/
		int h /*Variable holding image height*/
		)
{
    double prob_img[256] = {0}, transform[256] = {0};
    int i, j, pixel;
    int sz = h*w;

    ComputeHistogram(buffer,hist1, w, h);

    /*Computing the probability of occurrence of each intensity level*/
    for(i = 0; i < 256; i++)
        prob_img[i] = ((double) hist1[i]) / sz;

    /*The transformation function*/
    for(i = 0; i < 256; i++)
    {
        for(j = 0; j < i; j++)
            transform[i] = transform[i] + (255 * prob_img[j]);
        transform[i] = round(transform[i]);
    }

    /*Assigning intensity level to each pixel calculated using the transformation
    function*/
    for(i = 0; i < sz; i++)
    {
        pixel = buffer[i];
        buffer[i] = transform[pixel];
    }

    /*Computing the histogram of the equalized image*/
    ComputeHistogram(buffer, hist1, w, h);
}




/*This function compares two image histograms using the intersection algorithm.*/
void HistogramComparison(
		      	         unsigned char *buffer1, /*Pointer to the first image data array*/
		      	         unsigned char *buffer3, /*Pointer to the second image data array*/
		      	         int *hist1, /*Pointer to the first image histogram array*/
		      	         int *hist3, /*Pointer to the first image histogram array*/
		      	         int w, /*Variable holding image width*/
		      	         int h /*Variable holding image height*/
		      	         )
{
    int result;
    double norm_res;
    int i;
    int sz = h*w;

    /*Computing the histogram of the first image*/
    ComputeHistogram(buffer1, hist1, w, h);
    /*Computing the histogram of the second image*/
    ComputeHistogram(buffer3, hist3, w, h);

    /*Calculating the intersection metric*/

    /*Adding the minimum count for each intensity level of the two histograms*/
    for(i = 0; i < 256; i++)
        if (hist1[i] < hist3[i])
            result += hist1[i];
        else
            result += hist3[i];
    /*Normalizing the result by dividing it by the size of the image*/
    norm_res = ((double)result) / sz;
    printf("\n\nThe result of histogram comparison by intersection metric is: %f\n\n", norm_res);
}

/*This function matches the histogram of the first image with that of a second image.*/
void HistogramMatching(
		  	     unsigned char *buffer2, /*Pointer to the first image data array*/
		  	     int *hist2, /*Pointer to the first image histogram array*/
		  	     unsigned char *buffer3, /*Pointer to the second image data array*/
		  	     int *hist3, /*Pointer to the second image histogram array*/
		  	     int *hist_match, /*Pointer to the matched image histogram array*/
		  	     int w, /*Variable holding image width*/
		  	     int h /*Variable holding image width*/
		  	     )
{
    double prob_img1[256] = {0}, transform2[256] = {0}, prob_img2[256] = {0},
    transform3[256] = {0};
    int i, j, pixel;
    int map[256] = {0};
    int sz = h*w;

    /*Processing the first image*/

    /*Computing the histogram of the first image*/
    ComputeHistogram(buffer2, hist2, w, h);

    /*Computing the probability of occurrence of each intensity level*/
    for(i = 0; i < 256; i++)
        prob_img1[i] = ((double) hist2[i]) / sz;

    /*The transformation function*/
    for(i = 0; i < 256; i++)
    {
        for(j = 0; j < i; j++)
            transform2[i] = transform2[i] + (255 * prob_img1[j]);
        transform2[i] = round(transform2[i]);
    }

    /*Assigning intensity level to each pixel calculated using the transformation
    function*/
    for(i = 0; i < sz; i++)
    {
        pixel = buffer2[i];
        buffer2[i] = transform2[pixel];
    }

    /*Processing the second image*/

    /*Computing the histogram of the second image*/
    ComputeHistogram(buffer3, hist3, w, h);

    /*Computing the probability of occurrence of each intensity level*/
    for(i = 0; i < 256; i++)
        prob_img2[i] = ((double) hist3[i]) / sz;

    /*The transformation function*/
    for(i = 0; i < 256; i++)
    {
        for(j = 0; j < i; j++)
            transform3[i] = transform3[i] + (255 * prob_img2[j]);
        transform3[i] = round(transform3[i]);
    }

    /*Assigning intensity level to each pixel calculated using the transformation
    function*/
    for(i = 0; i < sz; i++)
    {
        pixel = buffer3[i];
        buffer3[i] = transform3[pixel];
    }

    /*This code snippet searches for values in transformed intensity level count array of the second image which are same as the value in transformed intensity level count array of the first image at a certain intensity level and for each intensity level. When found it stores the intensity level (index of transform3[] array) of the matched second image in an array (here the array is called "map") at the index same as that of the first matched transformed intensity level count array. The values are allowed to differ by a few units as absolute similarity is unlikely.*/
    for(i = 0; i < 256; i++)
    {
        for(j = 0; j < 256; j++)
        {
            if (transform2[i] == transform3[j])
                map[i] = j;
            else if (transform2[i]+1 == transform3[j])
                map[i] = j;
            else if (transform2[i]-1 == transform3[j])
                map[i] = j;
        }
    }

    /*Assigning intensity level to each pixel calculated using the mapping code snippet*/
    for(i = 0; i < sz; i++)
    {
        pixel = buffer2[i];
        buffer2[i] = map[pixel];
    }

    /*Computing the histogram of the matched image*/
    ComputeHistogram(buffer2,hist_match, w, h);
}
