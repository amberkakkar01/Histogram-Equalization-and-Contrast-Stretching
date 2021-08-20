## <h2>Histogram Equalization & Contrast Stretching</h2>
```Histogram equalization is a method in image processing of contrast adjustment using the image's histogram.Histogram equalization is a method in image processing of contrast adjustment using the image's histogram.```

<h2>What is a Histogram of An Image?</h2>

```A histogram of an image is the graphical interpretation of the image’s pixel intensity values. It can be interpreted as the data structure that stores the frequencies of all the pixel intensity levels in the image.```

Histogram of an Image

 <img src="https://miro.medium.com/max/788/1*GCQn_KaJobChuZknKEUvlw.png" alt="Image"> 

As we can see in the image above, the X-axis represents the pixel intensity levels of the image. The intensity level usually ranges from 0 to 255. For a gray-scale image, there is only one histogram, whereas an RGB colored image will have three 2-D histograms — one for each color. The Y-axis of the histogram indicates the frequency or the number of pixels that have specific intensity values.
Histogram of a Gray-Scale Image
Histogram of an RGB Image

<h2>What is Histogram Equalization?</h2>

```Histogram Equalization is an image processing technique that adjusts the contrast of an image by using its histogram. To enhance the image’s contrast, it spreads out the most frequent pixel intensity values or stretches out the intensity range of the image. By accomplishing this, histogram equalization allows the image’s areas with lower contrast to gain a higher contrast.```

Graphical Representation of Histogram Equalization

 <img src="https://miro.medium.com/max/431/1*PWPxuPXr1CrRgJGo8vMH_g.jpeg" alt="Image"> 

<h2>Comparison of Original and Histogram Equalized Histograms</h2>
