# Andotrope
<img width="693" height="642" alt="afbeelding" src="https://github.com/user-attachments/assets/9265e5a2-7fa5-4903-844b-f7072b63b8f6" />

![IMG_20250727_183432](https://github.com/user-attachments/assets/d3fe4dba-8645-450b-af51-491c494197a4)

Open Source andotrope I made, for anyone that wants to build their own andotrope.
Credit to the idea of an andotrope goes to Mike Ando https://www.riumplus.com/gehns-holographic-imager-andotrope/
I came up with the method of creating the see through effect.

This is just a prototype and certain things don't work properly yet, please read the issues.

We use a rp2040 zero as the main microcontroller.

Here's a link to the specific screens i bought: 
https://nl.aliexpress.com/item/1005004662221931.html?spm=a2g0o.order_list.order_list_main.45.342279d2Cq6V3n&gatewayAdapt=glo2nld

Here's the link for the specific battery I bought:
https://www.amazon.com.be/-/nl/Lithium-polymeer-batterij-oplaadbare-connector/dp/B09DPP44C4/ref=sr_1_49?crid=2DGCH3SFM7T9Y&dib=eyJ2IjoiMSJ9.8MRHN6nsjn6rWcUjpGMPrWY0j2xv0fPXTWYNxfWofMixROA2xrdyIJKaopa5pxHBBI75-L6SN22FPPGtZX5OZ7Z9TBroLJ-eeARtyQQAdxwKBCn1AIRiqlJuRBfy318Pp8mZ5ea26fVgcEUHzXKW4zh8m-2FN1g8nhIcIWSPJ6bxrBKwXuq9ip4Wns2wsEUuukwkeq4bNFK2VB0fXXlntxXlQ5qIdWuJtqNhckXLF4XL6SS-KhW8iBYEFRrPiUnk5ZcpyS0m8zIDaoi9WfFQu_M5-0GlCY70lMdHUPG0hWq-Ts-pe1UP6Gm08eo5E-oseqIPQL-jlwrKrjUD7YBSCnK23rQ5kJMaqqLZGjWuUO0.KSeEQlK2RLbnNdtz2xeDAL1vn8DUBxZG1J9pjteS1aU&dib_tag=se&keywords=lipo+batterij&qid=1739394303&refinements=p_n_feature_ten_browse-bin%3A28198239031&rnid=28197428031&s=electronics&sprefix=lipo+battterij%2Caps%2C61&sr=1-49&xpid=nX4bC5qjEs3Ko

Here's a link for the specific motor I bought:
https://nl.aliexpress.com/item/4001118243931.html?spm=a2g0o.order_list.order_list_main.50.342279d2Cq6V3n&gatewayAdapt=glo2nld 

Here's a link for the specific magnets I bought:
https://www.digikey.be/nl/products/detail/radial-magnets-inc/8996/5126078

Here's a link for the specific power connector I bought for the motor:
https://www.digikey.be/nl/products/detail/tensility-international-corp/54-00287/16649080 

The powerbrick isn't for sale anymore so you'll have to buy your own 6V barrel connector powerbrick.

Here's the link for the polarised film I used: 
https://nl.aliexpress.com/item/1005006054349865.html?spm=a2g0o.order_list.order_list_main.5.342279d2Cq6V3n&gatewayAdapt=glo2nld 

Unfortunately the screens themselves are polarised at a 45° angle so you'll have to add another polarisation filter on top if it polarising it horizontally or vertically so the wrap around filter doesn't block the light coming from the filter at the opposite side of the screen holder but only blocks light from the screen itself.

here's the heat inserts I used:
https://nl.aliexpress.com/item/1005003582355741.html?spm=a2g0o.order_list.order_list_main.23.342279d2Cq6V3n&gatewayAdapt=glo2nld

Here's the screws I used for the heat inserts:
https://nl.aliexpress.com/item/1005005070119421.html?spm=a2g0o.order_list.order_list_main.11.342279d2Cq6V3n&gatewayAdapt=glo2nld 

I sourced the powerswitch from old christmas lights and soldered it in between the batteries power line. 

The rest of the components you should be able to source from the bill of materials of the scematic.

Here's some more important tips:

Do not solder the mosfet to the bord but rather bridge the source and drain.
I myself glued the screens to the screen holder using double sided tape.
The polarised film has a protective film on both sides that needs to be removed, be carefull because one side of the film is very sticky and should be oriented inwards. This sticky side does help with sticking it to the screens but not to the outside of the screen holder. I used zip ties for that.

