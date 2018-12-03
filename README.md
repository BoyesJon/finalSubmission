# Computer Graphics – Final Image

### Description

In this image, I have modified my Ray Tracer system to incorperate a new type of lighting. In A3, we only had directional and point lights. However, what was not discussed was lights that did not just make everything in the scene bright. What I wanted to acomplish was to implement exactly this: A light that only has a certain area of effect.

What I found was something called "Light Attenuation". With this, point lights can now have the extra characterisitic of being "dim". That is, it does not just light everything up, but rather, only things within range. The algorithm I used to determine this was adapted from the url: https://imdoingitwrong.wordpress.com/2011/01/31/light-attenuation/

In the picture, we see this light at work. The general scene is being lit up by a directional light coming from the viewing angle. There are also three point lights, a green one, a red one, and a blue one, all positioned infront of one sphere. The right sphere is being lit up by both the green and blue lights. The left spere is being lit up by the red and blue lights. The middle sphere is under the lighting of all three lights. Note that parts of the spheres are not being entirely illuminated, only the parts within the range of the light. You can see this effect slightly better by looking at the table, as well as the back-ground, where the coloured lights gradually fade away.

Along side this, I also created a new object to be renered: a rectangular prism. The algorithm for finding a ray intersection with this object was based off of my A4 solution. However, that did not quite work out, so I switched to an algorithim described on:
https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-box-intersection

Looking closely, you can also see small legs holding up the table (they are dark due to a lack of lighting), and can also see that the table base is not just an endless plane.

Unfortunately I did not implement everthing I wanted (for one reason or another). Some things that I missed include:
- Creating a new cylinder object to be rendered
- Creating transparent/translucent objects for light to travel through (the light colour would be modified if it passed
  through one of these objects)
- Incorperating the AABB-tree code that I wrote for A4 so that rendering would be notably faster.
- Originally, I wanted to make a scene of an empty cabin with light pouring through a window. In the corner would be a dim amber
  light. I was unable to obtain the effect that I wanted, so I switched to a simpler idea.

### Code acknowledgment
As mentioned above, some code has been based off of already-existing algorithms and/or already-written code. These include:
https://imdoingitwrong.wordpress.com/2011/01/31/light-attenuation/ - Light Attenuation
https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-box-intersection - Ray-box intersection

Along side this, the read_json.h file was slightly modified from its original form to incorperate dim lights and rectangular prism objects. The Light.h file was also modified to include Light Attenuation. I was originally going to modify just pointLight.h, however accessing the desired info would become troublesome.

The code in the SRC folder was all written by me, and originally came from my A3 submission. Any acknowledgements that I may have missed can be found in those files. I also made RectPrism.h, which was based off of the other object.h files.

All other files, such as main.cpp or other .h files were provided by the CSC418 course.