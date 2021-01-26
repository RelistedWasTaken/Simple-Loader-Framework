# Simple-Loader-Framework
<h1>FRAMEWORK USAGE:</h1>

<h3>INPUT REQUEST INFO IN UTILS.H</h3>
</br></br>

<h4>Menu menu("Title")</h4>
  creates a menu class with a title.
</br></br>

<h4>menu.add_item_float(1.f)</h4>
  adds a floating point to the menu
  </br></br>
  
<h4>menu.add_item_int(1)</h4>
  adds an integer to the menu
</br></br>

<h4>menu.add_item_string("india")</h4>
  adds a string to the menu
  </br></br>
  
<h4>download_file_from_url(src, dest)</h4>		
  downloads a file from a source (url) given
  </br></br>
  
<h4>open_app_insecure(DESTINATION, args, b_hidden)</h4>
  execute executable file from a destination given
</br></br>

<h4>ping_new(PING_DEST)</h4>
  pings website and returns true or false depending of whether its online
  </br></br>
  
<h4>ping_old(PING_DEST)</h4>					
  pings website and returns 1 or >1 depending on returned packet
  WARNING: slow, ineffective and can compromise user if used.
  </br></br>
  
<h4>get_user_name()</h4>
  returns current user name as a string value
  </br></br>
  
 <h4>pause_until_leave()</h4>
 pauses the app and exits it when a key is pressed
   </br></br>
   
<h4>is_key_allowed_insecure()	</h4>				
check if given key is allowed returns true or false
usage:</br>
</br>
if (!is_key_allowed_insecure(key_input)) { menu.add_item_string("wrong key."); return 0; }</br>
else { menu.add_item_string("key correct."); }</br>

</br></br>
<h4>is_key_allowed_secure()</h4>						
usage: (i know its bad)</br>
</br>
is_key_allowed_secure(key_input)</br>
if (*result == t_ - f_) { menu.add_item_string("wrong key."); return 0; }</br>
else if (*result == t_ + f_) { menu.add_item_string("key correct."); }</br>
</br></br>

<h1>EXAMPLE OUTPUT:</h1>
successful output:
<img src="https://user-images.githubusercontent.com/73892791/105888887-d9cf1280-600d-11eb-8e89-c52c0ebe925f.png" width="50%"></img> 
wrong key:
<img src="https://user-images.githubusercontent.com/73892791/105889230-3d594000-600e-11eb-93c5-ea1138411143.png" width="50%"></img> 
download error:
<img src="https://user-images.githubusercontent.com/73892791/105889409-6b3e8480-600e-11eb-8e2e-31f6b610a411.png" width="50%"></img> 
