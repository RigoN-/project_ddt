<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns='http://www.w3.org/1999/xhtml' xml:lang='en' lang='en'>
<head>
<title>mesa/mesa - The Mesa 3D Graphics Library</title>
<meta name='generator' content='cgit v0.9.0.2-2-gbebe'/>
<meta name='robots' content='index, nofollow'/>
<link rel='stylesheet' type='text/css' href='http://cgit.freedesktop.org/cgit.css'/>
<link rel='alternate' title='Atom feed' href='http://cgit.freedesktop.org/mesa/mesa/atom/include/GL/glx.h?h=master' type='application/atom+xml'/>
</head>
<body>
<div id='cgit'><table id='header'>
<tr>
<td class='logo' rowspan='2'><a href='/'><img src='http://cgit.freedesktop.org/logo.png' alt='cgit logo'/></a></td>
<td class='main'><a href='/'>index</a> : <a title='mesa/mesa' href='/mesa/mesa/'>mesa/mesa</a></td><td class='form'><form method='get' action=''>
<select name='h' onchange='this.form.submit();'>
<option value='7.10'>7.10</option>
<option value='7.11'>7.11</option>
<option value='7.8'>7.8</option>
<option value='7.8-gles'>7.8-gles</option>
<option value='7.9'>7.9</option>
<option value='8.0'>8.0</option>
<option value='9.0'>9.0</option>
<option value='9.1'>9.1</option>
<option value='9.2'>9.2</option>
<option value='965-glsl'>965-glsl</option>
<option value='965-ttm'>965-ttm</option>
<option value='R300_DRIVER'>R300_DRIVER</option>
<option value='arb_copy_buffer'>arb_copy_buffer</option>
<option value='arb_fbo'>arb_fbo</option>
<option value='arb_fbo_cleanup'>arb_fbo_cleanup</option>
<option value='arb_fbo_indirect'>arb_fbo_indirect</option>
<option value='arb_geometry_shader4'>arb_geometry_shader4</option>
<option value='arb_half_float_vertex'>arb_half_float_vertex</option>
<option value='arb_map_buffer_range'>arb_map_buffer_range</option>
<option value='arb_robustness'>arb_robustness</option>
<option value='arb_sampler_objects'>arb_sampler_objects</option>
<option value='arb_sync'>arb_sync</option>
<option value='arb_vertex_array_object'>arb_vertex_array_object</option>
<option value='asm-shader-rework-1'>asm-shader-rework-1</option>
<option value='asm-shader-rework-2'>asm-shader-rework-2</option>
<option value='asm-shader-rework-3'>asm-shader-rework-3</option>
<option value='auto-cherry-for-8.0'>auto-cherry-for-8.0</option>
<option value='autoconf'>autoconf</option>
<option value='cxx-1-branch'>cxx-1-branch</option>
<option value='d3d1x-addons'>d3d1x-addons</option>
<option value='draw-instanced'>draw-instanced</option>
<option value='draw-ply'>draw-ply</option>
<option value='dri2-swapbuffers'>dri2-swapbuffers</option>
<option value='drm-gem'>drm-gem</option>
<option value='embedded-1-branch'>embedded-1-branch</option>
<option value='embedded-2-branch'>embedded-2-branch</option>
<option value='experimental-1'>experimental-1</option>
<option value='ext-provoking-vertex'>ext-provoking-vertex</option>
<option value='flex-and-bison-required'>flex-and-bison-required</option>
<option value='floating'>floating</option>
<option value='frontbuffer-removal'>frontbuffer-removal</option>
<option value='gallium-0.1'>gallium-0.1</option>
<option value='gallium-0.1-dri'>gallium-0.1-dri</option>
<option value='gallium-0.1-dri2'>gallium-0.1-dri2</option>
<option value='gallium-0.2'>gallium-0.2</option>
<option value='gallium-array-textures'>gallium-array-textures</option>
<option value='gallium-buffer-usage-cleanup'>gallium-buffer-usage-cleanup</option>
<option value='gallium-clip-state'>gallium-clip-state</option>
<option value='gallium-compute'>gallium-compute</option>
<option value='gallium-context-transfers-2'>gallium-context-transfers-2</option>
<option value='gallium-cylindrical-wrap'>gallium-cylindrical-wrap</option>
<option value='gallium-double-opcodes'>gallium-double-opcodes</option>
<option value='gallium-drm-driver-descriptor'>gallium-drm-driver-descriptor</option>
<option value='gallium-dynamicstencilref'>gallium-dynamicstencilref</option>
<option value='gallium-fb-dimensions'>gallium-fb-dimensions</option>
<option value='gallium-float-1111-format'>gallium-float-1111-format</option>
<option value='gallium-format-cleanup'>gallium-format-cleanup</option>
<option value='gallium-front-ccw'>gallium-front-ccw</option>
<option value='gallium-gpu4-texture-opcodes'>gallium-gpu4-texture-opcodes</option>
<option value='gallium-integer-opcodes'>gallium-integer-opcodes</option>
<option value='gallium-llvmpipe'>gallium-llvmpipe</option>
<option value='gallium-mesa-7.4'>gallium-mesa-7.4</option>
<option value='gallium-msaa'>gallium-msaa</option>
<option value='gallium-new-formats'>gallium-new-formats</option>
<option value='gallium-newclear'>gallium-newclear</option>
<option value='gallium-no-nvidia-opcodes'>gallium-no-nvidia-opcodes</option>
<option value='gallium-no-rhw-position'>gallium-no-rhw-position</option>
<option value='gallium-no-texture-blanket'>gallium-no-texture-blanket</option>
<option value='gallium-nopointsizeminmax'>gallium-nopointsizeminmax</option>
<option value='gallium-render-condition-predicate'>gallium-render-condition-predicate</option>
<option value='gallium-resource-sampling'>gallium-resource-sampling</option>
<option value='gallium-resources'>gallium-resources</option>
<option value='gallium-sampler-view'>gallium-sampler-view</option>
<option value='gallium-softpipe-winsys'>gallium-softpipe-winsys</option>
<option value='gallium-st-api'>gallium-st-api</option>
<option value='gallium-st-api-dri'>gallium-st-api-dri</option>
<option value='gallium-stream-out'>gallium-stream-out</option>
<option value='gallium-sw-api'>gallium-sw-api</option>
<option value='gallium-tgsi-semantic-cleanup'>gallium-tgsi-semantic-cleanup</option>
<option value='gallium-userbuf'>gallium-userbuf</option>
<option value='gallium-util-format-is-supported'>gallium-util-format-is-supported</option>
<option value='gallium-vertexelementcso'>gallium-vertexelementcso</option>
<option value='gallium_draw_llvm'>gallium_draw_llvm</option>
<option value='gallivm-call'>gallivm-call</option>
<option value='glapi-reorg'>glapi-reorg</option>
<option value='gles3'>gles3</option>
<option value='glsl-compiler-1'>glsl-compiler-1</option>
<option value='glsl-continue-return'>glsl-continue-return</option>
<option value='glsl-continue-return-7-5'>glsl-continue-return-7-5</option>
<option value='glsl-pp-rework-1'>glsl-pp-rework-1</option>
<option value='glsl-pp-rework-2'>glsl-pp-rework-2</option>
<option value='glsl-to-tgsi'>glsl-to-tgsi</option>
<option value='glsl2'>glsl2</option>
<option value='glsl2-llvm'>glsl2-llvm</option>
<option value='glsl2-lower-variable-indexing'>glsl2-lower-variable-indexing</option>
<option value='graw-tests'>graw-tests</option>
<option value='hw_gl_select'>hw_gl_select</option>
<option value='i915tex-pageflip'>i915tex-pageflip</option>
<option value='i915tex-zone-rendering'>i915tex-zone-rendering</option>
<option value='i915tex_branch'>i915tex_branch</option>
<option value='i915tex_privbuffers'>i915tex_privbuffers</option>
<option value='index-swtnl-0.1'>index-swtnl-0.1</option>
<option value='indirect-vbo'>indirect-vbo</option>
<option value='intel-2008-q3'>intel-2008-q3</option>
<option value='intel-2008-q4'>intel-2008-q4</option>
<option value='kasanen-post-process'>kasanen-post-process</option>
<option value='kasanen-post-process-v2'>kasanen-post-process-v2</option>
<option value='llvm-cliptest-viewport'>llvm-cliptest-viewport</option>
<option value='llvm-context'>llvm-context</option>
<option value='llvmpipe-duma'>llvmpipe-duma</option>
<option value='llvmpipe-wider-regs'>llvmpipe-wider-regs</option>
<option value='lp-line-rast'>lp-line-rast</option>
<option value='lp-offset-twoside'>lp-offset-twoside</option>
<option value='lp-setup-llvm'>lp-setup-llvm</option>
<option value='lp-surface-tiling'>lp-surface-tiling</option>
<option value='map-tex-branch'>map-tex-branch</option>
<option value='map-texture-image-v4'>map-texture-image-v4</option>
<option value='map-texture-image-v5'>map-texture-image-v5</option>
<option value='master' selected='selected'>master</option>
<option value='mesa'>mesa</option>
<option value='mesa_20040127_branch'>mesa_20040127_branch</option>
<option value='mesa_20040309_branch'>mesa_20040309_branch</option>
<option value='mesa_20050114_branch'>mesa_20050114_branch</option>
<option value='mesa_3_2_dev'>mesa_3_2_dev</option>
<option value='mesa_3_3_texture_env_combine2'>mesa_3_3_texture_env_combine2</option>
<option value='mesa_3_4_branch'>mesa_3_4_branch</option>
<option value='mesa_4_0_branch'>mesa_4_0_branch</option>
<option value='mesa_5_0_branch'>mesa_5_0_branch</option>
<option value='mesa_6_0_branch'>mesa_6_0_branch</option>
<option value='mesa_6_2_branch'>mesa_6_2_branch</option>
<option value='mesa_6_4_branch'>mesa_6_4_branch</option>
<option value='mesa_7_0_branch'>mesa_7_0_branch</option>
<option value='mesa_7_2_branch'>mesa_7_2_branch</option>
<option value='mesa_7_4_branch'>mesa_7_4_branch</option>
<option value='mesa_7_4_idr_staging'>mesa_7_4_idr_staging</option>
<option value='mesa_7_5_branch'>mesa_7_5_branch</option>
<option value='mesa_7_6_branch'>mesa_7_6_branch</option>
<option value='mesa_7_7_branch'>mesa_7_7_branch</option>
<option value='nv50-compiler'>nv50-compiler</option>
<option value='nvc0'>nvc0</option>
<option value='openchrome-branch'>openchrome-branch</option>
<option value='opengl-es'>opengl-es</option>
<option value='opengl-es-v2'>opengl-es-v2</option>
<option value='openvg-1.0'>openvg-1.0</option>
<option value='outputswritten64'>outputswritten64</option>
<option value='pipe-video'>pipe-video</option>
<option value='primitive-restart'>primitive-restart</option>
<option value='r300-bufmgr'>r300-bufmgr</option>
<option value='r500-support'>r500-support</option>
<option value='r6xx-r7xx-support'>r6xx-r7xx-support</option>
<option value='r6xx-rewrite'>r6xx-rewrite</option>
<option value='radeon-rewrite'>radeon-rewrite</option>
<option value='remove-copyteximage-hook'>remove-copyteximage-hook</option>
<option value='remove-driver-date'>remove-driver-date</option>
<option value='remove-max-width'>remove-max-width</option>
<option value='remove-max-width-2'>remove-max-width-2</option>
<option value='remove-redundant-helpers'>remove-redundant-helpers</option>
<option value='renderbuffer-cleanups-v2'>renderbuffer-cleanups-v2</option>
<option value='shader-file-reorg'>shader-file-reorg</option>
<option value='shader-work'>shader-work</option>
<option value='softpipe_0_1_branch'>softpipe_0_1_branch</option>
<option value='sprite-coord'>sprite-coord</option>
<option value='st-mesa-per-context-shaders'>st-mesa-per-context-shaders</option>
<option value='st-vbo'>st-vbo</option>
<option value='texfilter_float_branch'>texfilter_float_branch</option>
<option value='texformat-xrgb'>texformat-xrgb</option>
<option value='texman_0_1_branch'>texman_0_1_branch</option>
<option value='texmem-1.0'>texmem-1.0</option>
<option value='texmem_0_2_branch'>texmem_0_2_branch</option>
<option value='texmem_0_3_branch'>texmem_0_3_branch</option>
<option value='texture_rg'>texture_rg</option>
<option value='texture_rg-2'>texture_rg-2</option>
<option value='thalloc'>thalloc</option>
<option value='vbo_0_1_branch'>vbo_0_1_branch</option>
<option value='vtx-0-1-branch'>vtx-0-1-branch</option>
<option value='vtx-0-2-branch'>vtx-0-2-branch</option>
<option value='xa_branch'>xa_branch</option>
</select> <input type='submit' name='' value='switch'/></form></td></tr>
<tr><td class='sub'>The Mesa 3D Graphics Library</td><td class='sub right'>brianp</td></tr></table>
<table class='tabs'><tr><td>
<a href='/mesa/mesa/'>summary</a><a href='/mesa/mesa/refs/'>refs</a><a href='/mesa/mesa/log/include/GL/glx.h'>log</a><a class='active' href='/mesa/mesa/tree/include/GL/glx.h'>tree</a><a href='/mesa/mesa/commit/include/GL/glx.h'>commit</a><a href='/mesa/mesa/diff/include/GL/glx.h'>diff</a></td><td class='form'><form class='right' method='get' action='/mesa/mesa/log/include/GL/glx.h'>
<select name='qt'>
<option value='grep'>log msg</option>
<option value='author'>author</option>
<option value='committer'>committer</option>
<option value='range'>range</option>
</select>
<input class='txt' type='text' size='10' name='q' value=''/>
<input type='submit' value='search'/>
</form>
</td></tr></table>
<div class='path'>path: <a href='/mesa/mesa/tree/'>root</a>/<a href='/mesa/mesa/tree/include'>include</a>/<a href='/mesa/mesa/tree/include/GL'>GL</a>/<a href='/mesa/mesa/tree/include/GL/glx.h'>glx.h</a></div><div class='content'>blob: 87c31fdcc158ed145df0320fab36dad560ae410a (<a href='/mesa/mesa/plain/include/GL/glx.h'>plain</a>)
<table summary='blob content' class='blob'>
<tr><td class='linenumbers'><pre><a class='no' id='n1' name='n1' href='#n1'>1</a>
<a class='no' id='n2' name='n2' href='#n2'>2</a>
<a class='no' id='n3' name='n3' href='#n3'>3</a>
<a class='no' id='n4' name='n4' href='#n4'>4</a>
<a class='no' id='n5' name='n5' href='#n5'>5</a>
<a class='no' id='n6' name='n6' href='#n6'>6</a>
<a class='no' id='n7' name='n7' href='#n7'>7</a>
<a class='no' id='n8' name='n8' href='#n8'>8</a>
<a class='no' id='n9' name='n9' href='#n9'>9</a>
<a class='no' id='n10' name='n10' href='#n10'>10</a>
<a class='no' id='n11' name='n11' href='#n11'>11</a>
<a class='no' id='n12' name='n12' href='#n12'>12</a>
<a class='no' id='n13' name='n13' href='#n13'>13</a>
<a class='no' id='n14' name='n14' href='#n14'>14</a>
<a class='no' id='n15' name='n15' href='#n15'>15</a>
<a class='no' id='n16' name='n16' href='#n16'>16</a>
<a class='no' id='n17' name='n17' href='#n17'>17</a>
<a class='no' id='n18' name='n18' href='#n18'>18</a>
<a class='no' id='n19' name='n19' href='#n19'>19</a>
<a class='no' id='n20' name='n20' href='#n20'>20</a>
<a class='no' id='n21' name='n21' href='#n21'>21</a>
<a class='no' id='n22' name='n22' href='#n22'>22</a>
<a class='no' id='n23' name='n23' href='#n23'>23</a>
<a class='no' id='n24' name='n24' href='#n24'>24</a>
<a class='no' id='n25' name='n25' href='#n25'>25</a>
<a class='no' id='n26' name='n26' href='#n26'>26</a>
<a class='no' id='n27' name='n27' href='#n27'>27</a>
<a class='no' id='n28' name='n28' href='#n28'>28</a>
<a class='no' id='n29' name='n29' href='#n29'>29</a>
<a class='no' id='n30' name='n30' href='#n30'>30</a>
<a class='no' id='n31' name='n31' href='#n31'>31</a>
<a class='no' id='n32' name='n32' href='#n32'>32</a>
<a class='no' id='n33' name='n33' href='#n33'>33</a>
<a class='no' id='n34' name='n34' href='#n34'>34</a>
<a class='no' id='n35' name='n35' href='#n35'>35</a>
<a class='no' id='n36' name='n36' href='#n36'>36</a>
<a class='no' id='n37' name='n37' href='#n37'>37</a>
<a class='no' id='n38' name='n38' href='#n38'>38</a>
<a class='no' id='n39' name='n39' href='#n39'>39</a>
<a class='no' id='n40' name='n40' href='#n40'>40</a>
<a class='no' id='n41' name='n41' href='#n41'>41</a>
<a class='no' id='n42' name='n42' href='#n42'>42</a>
<a class='no' id='n43' name='n43' href='#n43'>43</a>
<a class='no' id='n44' name='n44' href='#n44'>44</a>
<a class='no' id='n45' name='n45' href='#n45'>45</a>
<a class='no' id='n46' name='n46' href='#n46'>46</a>
<a class='no' id='n47' name='n47' href='#n47'>47</a>
<a class='no' id='n48' name='n48' href='#n48'>48</a>
<a class='no' id='n49' name='n49' href='#n49'>49</a>
<a class='no' id='n50' name='n50' href='#n50'>50</a>
<a class='no' id='n51' name='n51' href='#n51'>51</a>
<a class='no' id='n52' name='n52' href='#n52'>52</a>
<a class='no' id='n53' name='n53' href='#n53'>53</a>
<a class='no' id='n54' name='n54' href='#n54'>54</a>
<a class='no' id='n55' name='n55' href='#n55'>55</a>
<a class='no' id='n56' name='n56' href='#n56'>56</a>
<a class='no' id='n57' name='n57' href='#n57'>57</a>
<a class='no' id='n58' name='n58' href='#n58'>58</a>
<a class='no' id='n59' name='n59' href='#n59'>59</a>
<a class='no' id='n60' name='n60' href='#n60'>60</a>
<a class='no' id='n61' name='n61' href='#n61'>61</a>
<a class='no' id='n62' name='n62' href='#n62'>62</a>
<a class='no' id='n63' name='n63' href='#n63'>63</a>
<a class='no' id='n64' name='n64' href='#n64'>64</a>
<a class='no' id='n65' name='n65' href='#n65'>65</a>
<a class='no' id='n66' name='n66' href='#n66'>66</a>
<a class='no' id='n67' name='n67' href='#n67'>67</a>
<a class='no' id='n68' name='n68' href='#n68'>68</a>
<a class='no' id='n69' name='n69' href='#n69'>69</a>
<a class='no' id='n70' name='n70' href='#n70'>70</a>
<a class='no' id='n71' name='n71' href='#n71'>71</a>
<a class='no' id='n72' name='n72' href='#n72'>72</a>
<a class='no' id='n73' name='n73' href='#n73'>73</a>
<a class='no' id='n74' name='n74' href='#n74'>74</a>
<a class='no' id='n75' name='n75' href='#n75'>75</a>
<a class='no' id='n76' name='n76' href='#n76'>76</a>
<a class='no' id='n77' name='n77' href='#n77'>77</a>
<a class='no' id='n78' name='n78' href='#n78'>78</a>
<a class='no' id='n79' name='n79' href='#n79'>79</a>
<a class='no' id='n80' name='n80' href='#n80'>80</a>
<a class='no' id='n81' name='n81' href='#n81'>81</a>
<a class='no' id='n82' name='n82' href='#n82'>82</a>
<a class='no' id='n83' name='n83' href='#n83'>83</a>
<a class='no' id='n84' name='n84' href='#n84'>84</a>
<a class='no' id='n85' name='n85' href='#n85'>85</a>
<a class='no' id='n86' name='n86' href='#n86'>86</a>
<a class='no' id='n87' name='n87' href='#n87'>87</a>
<a class='no' id='n88' name='n88' href='#n88'>88</a>
<a class='no' id='n89' name='n89' href='#n89'>89</a>
<a class='no' id='n90' name='n90' href='#n90'>90</a>
<a class='no' id='n91' name='n91' href='#n91'>91</a>
<a class='no' id='n92' name='n92' href='#n92'>92</a>
<a class='no' id='n93' name='n93' href='#n93'>93</a>
<a class='no' id='n94' name='n94' href='#n94'>94</a>
<a class='no' id='n95' name='n95' href='#n95'>95</a>
<a class='no' id='n96' name='n96' href='#n96'>96</a>
<a class='no' id='n97' name='n97' href='#n97'>97</a>
<a class='no' id='n98' name='n98' href='#n98'>98</a>
<a class='no' id='n99' name='n99' href='#n99'>99</a>
<a class='no' id='n100' name='n100' href='#n100'>100</a>
<a class='no' id='n101' name='n101' href='#n101'>101</a>
<a class='no' id='n102' name='n102' href='#n102'>102</a>
<a class='no' id='n103' name='n103' href='#n103'>103</a>
<a class='no' id='n104' name='n104' href='#n104'>104</a>
<a class='no' id='n105' name='n105' href='#n105'>105</a>
<a class='no' id='n106' name='n106' href='#n106'>106</a>
<a class='no' id='n107' name='n107' href='#n107'>107</a>
<a class='no' id='n108' name='n108' href='#n108'>108</a>
<a class='no' id='n109' name='n109' href='#n109'>109</a>
<a class='no' id='n110' name='n110' href='#n110'>110</a>
<a class='no' id='n111' name='n111' href='#n111'>111</a>
<a class='no' id='n112' name='n112' href='#n112'>112</a>
<a class='no' id='n113' name='n113' href='#n113'>113</a>
<a class='no' id='n114' name='n114' href='#n114'>114</a>
<a class='no' id='n115' name='n115' href='#n115'>115</a>
<a class='no' id='n116' name='n116' href='#n116'>116</a>
<a class='no' id='n117' name='n117' href='#n117'>117</a>
<a class='no' id='n118' name='n118' href='#n118'>118</a>
<a class='no' id='n119' name='n119' href='#n119'>119</a>
<a class='no' id='n120' name='n120' href='#n120'>120</a>
<a class='no' id='n121' name='n121' href='#n121'>121</a>
<a class='no' id='n122' name='n122' href='#n122'>122</a>
<a class='no' id='n123' name='n123' href='#n123'>123</a>
<a class='no' id='n124' name='n124' href='#n124'>124</a>
<a class='no' id='n125' name='n125' href='#n125'>125</a>
<a class='no' id='n126' name='n126' href='#n126'>126</a>
<a class='no' id='n127' name='n127' href='#n127'>127</a>
<a class='no' id='n128' name='n128' href='#n128'>128</a>
<a class='no' id='n129' name='n129' href='#n129'>129</a>
<a class='no' id='n130' name='n130' href='#n130'>130</a>
<a class='no' id='n131' name='n131' href='#n131'>131</a>
<a class='no' id='n132' name='n132' href='#n132'>132</a>
<a class='no' id='n133' name='n133' href='#n133'>133</a>
<a class='no' id='n134' name='n134' href='#n134'>134</a>
<a class='no' id='n135' name='n135' href='#n135'>135</a>
<a class='no' id='n136' name='n136' href='#n136'>136</a>
<a class='no' id='n137' name='n137' href='#n137'>137</a>
<a class='no' id='n138' name='n138' href='#n138'>138</a>
<a class='no' id='n139' name='n139' href='#n139'>139</a>
<a class='no' id='n140' name='n140' href='#n140'>140</a>
<a class='no' id='n141' name='n141' href='#n141'>141</a>
<a class='no' id='n142' name='n142' href='#n142'>142</a>
<a class='no' id='n143' name='n143' href='#n143'>143</a>
<a class='no' id='n144' name='n144' href='#n144'>144</a>
<a class='no' id='n145' name='n145' href='#n145'>145</a>
<a class='no' id='n146' name='n146' href='#n146'>146</a>
<a class='no' id='n147' name='n147' href='#n147'>147</a>
<a class='no' id='n148' name='n148' href='#n148'>148</a>
<a class='no' id='n149' name='n149' href='#n149'>149</a>
<a class='no' id='n150' name='n150' href='#n150'>150</a>
<a class='no' id='n151' name='n151' href='#n151'>151</a>
<a class='no' id='n152' name='n152' href='#n152'>152</a>
<a class='no' id='n153' name='n153' href='#n153'>153</a>
<a class='no' id='n154' name='n154' href='#n154'>154</a>
<a class='no' id='n155' name='n155' href='#n155'>155</a>
<a class='no' id='n156' name='n156' href='#n156'>156</a>
<a class='no' id='n157' name='n157' href='#n157'>157</a>
<a class='no' id='n158' name='n158' href='#n158'>158</a>
<a class='no' id='n159' name='n159' href='#n159'>159</a>
<a class='no' id='n160' name='n160' href='#n160'>160</a>
<a class='no' id='n161' name='n161' href='#n161'>161</a>
<a class='no' id='n162' name='n162' href='#n162'>162</a>
<a class='no' id='n163' name='n163' href='#n163'>163</a>
<a class='no' id='n164' name='n164' href='#n164'>164</a>
<a class='no' id='n165' name='n165' href='#n165'>165</a>
<a class='no' id='n166' name='n166' href='#n166'>166</a>
<a class='no' id='n167' name='n167' href='#n167'>167</a>
<a class='no' id='n168' name='n168' href='#n168'>168</a>
<a class='no' id='n169' name='n169' href='#n169'>169</a>
<a class='no' id='n170' name='n170' href='#n170'>170</a>
<a class='no' id='n171' name='n171' href='#n171'>171</a>
<a class='no' id='n172' name='n172' href='#n172'>172</a>
<a class='no' id='n173' name='n173' href='#n173'>173</a>
<a class='no' id='n174' name='n174' href='#n174'>174</a>
<a class='no' id='n175' name='n175' href='#n175'>175</a>
<a class='no' id='n176' name='n176' href='#n176'>176</a>
<a class='no' id='n177' name='n177' href='#n177'>177</a>
<a class='no' id='n178' name='n178' href='#n178'>178</a>
<a class='no' id='n179' name='n179' href='#n179'>179</a>
<a class='no' id='n180' name='n180' href='#n180'>180</a>
<a class='no' id='n181' name='n181' href='#n181'>181</a>
<a class='no' id='n182' name='n182' href='#n182'>182</a>
<a class='no' id='n183' name='n183' href='#n183'>183</a>
<a class='no' id='n184' name='n184' href='#n184'>184</a>
<a class='no' id='n185' name='n185' href='#n185'>185</a>
<a class='no' id='n186' name='n186' href='#n186'>186</a>
<a class='no' id='n187' name='n187' href='#n187'>187</a>
<a class='no' id='n188' name='n188' href='#n188'>188</a>
<a class='no' id='n189' name='n189' href='#n189'>189</a>
<a class='no' id='n190' name='n190' href='#n190'>190</a>
<a class='no' id='n191' name='n191' href='#n191'>191</a>
<a class='no' id='n192' name='n192' href='#n192'>192</a>
<a class='no' id='n193' name='n193' href='#n193'>193</a>
<a class='no' id='n194' name='n194' href='#n194'>194</a>
<a class='no' id='n195' name='n195' href='#n195'>195</a>
<a class='no' id='n196' name='n196' href='#n196'>196</a>
<a class='no' id='n197' name='n197' href='#n197'>197</a>
<a class='no' id='n198' name='n198' href='#n198'>198</a>
<a class='no' id='n199' name='n199' href='#n199'>199</a>
<a class='no' id='n200' name='n200' href='#n200'>200</a>
<a class='no' id='n201' name='n201' href='#n201'>201</a>
<a class='no' id='n202' name='n202' href='#n202'>202</a>
<a class='no' id='n203' name='n203' href='#n203'>203</a>
<a class='no' id='n204' name='n204' href='#n204'>204</a>
<a class='no' id='n205' name='n205' href='#n205'>205</a>
<a class='no' id='n206' name='n206' href='#n206'>206</a>
<a class='no' id='n207' name='n207' href='#n207'>207</a>
<a class='no' id='n208' name='n208' href='#n208'>208</a>
<a class='no' id='n209' name='n209' href='#n209'>209</a>
<a class='no' id='n210' name='n210' href='#n210'>210</a>
<a class='no' id='n211' name='n211' href='#n211'>211</a>
<a class='no' id='n212' name='n212' href='#n212'>212</a>
<a class='no' id='n213' name='n213' href='#n213'>213</a>
<a class='no' id='n214' name='n214' href='#n214'>214</a>
<a class='no' id='n215' name='n215' href='#n215'>215</a>
<a class='no' id='n216' name='n216' href='#n216'>216</a>
<a class='no' id='n217' name='n217' href='#n217'>217</a>
<a class='no' id='n218' name='n218' href='#n218'>218</a>
<a class='no' id='n219' name='n219' href='#n219'>219</a>
<a class='no' id='n220' name='n220' href='#n220'>220</a>
<a class='no' id='n221' name='n221' href='#n221'>221</a>
<a class='no' id='n222' name='n222' href='#n222'>222</a>
<a class='no' id='n223' name='n223' href='#n223'>223</a>
<a class='no' id='n224' name='n224' href='#n224'>224</a>
<a class='no' id='n225' name='n225' href='#n225'>225</a>
<a class='no' id='n226' name='n226' href='#n226'>226</a>
<a class='no' id='n227' name='n227' href='#n227'>227</a>
<a class='no' id='n228' name='n228' href='#n228'>228</a>
<a class='no' id='n229' name='n229' href='#n229'>229</a>
<a class='no' id='n230' name='n230' href='#n230'>230</a>
<a class='no' id='n231' name='n231' href='#n231'>231</a>
<a class='no' id='n232' name='n232' href='#n232'>232</a>
<a class='no' id='n233' name='n233' href='#n233'>233</a>
<a class='no' id='n234' name='n234' href='#n234'>234</a>
<a class='no' id='n235' name='n235' href='#n235'>235</a>
<a class='no' id='n236' name='n236' href='#n236'>236</a>
<a class='no' id='n237' name='n237' href='#n237'>237</a>
<a class='no' id='n238' name='n238' href='#n238'>238</a>
<a class='no' id='n239' name='n239' href='#n239'>239</a>
<a class='no' id='n240' name='n240' href='#n240'>240</a>
<a class='no' id='n241' name='n241' href='#n241'>241</a>
<a class='no' id='n242' name='n242' href='#n242'>242</a>
<a class='no' id='n243' name='n243' href='#n243'>243</a>
<a class='no' id='n244' name='n244' href='#n244'>244</a>
<a class='no' id='n245' name='n245' href='#n245'>245</a>
<a class='no' id='n246' name='n246' href='#n246'>246</a>
<a class='no' id='n247' name='n247' href='#n247'>247</a>
<a class='no' id='n248' name='n248' href='#n248'>248</a>
<a class='no' id='n249' name='n249' href='#n249'>249</a>
<a class='no' id='n250' name='n250' href='#n250'>250</a>
<a class='no' id='n251' name='n251' href='#n251'>251</a>
<a class='no' id='n252' name='n252' href='#n252'>252</a>
<a class='no' id='n253' name='n253' href='#n253'>253</a>
<a class='no' id='n254' name='n254' href='#n254'>254</a>
<a class='no' id='n255' name='n255' href='#n255'>255</a>
<a class='no' id='n256' name='n256' href='#n256'>256</a>
<a class='no' id='n257' name='n257' href='#n257'>257</a>
<a class='no' id='n258' name='n258' href='#n258'>258</a>
<a class='no' id='n259' name='n259' href='#n259'>259</a>
<a class='no' id='n260' name='n260' href='#n260'>260</a>
<a class='no' id='n261' name='n261' href='#n261'>261</a>
<a class='no' id='n262' name='n262' href='#n262'>262</a>
<a class='no' id='n263' name='n263' href='#n263'>263</a>
<a class='no' id='n264' name='n264' href='#n264'>264</a>
<a class='no' id='n265' name='n265' href='#n265'>265</a>
<a class='no' id='n266' name='n266' href='#n266'>266</a>
<a class='no' id='n267' name='n267' href='#n267'>267</a>
<a class='no' id='n268' name='n268' href='#n268'>268</a>
<a class='no' id='n269' name='n269' href='#n269'>269</a>
<a class='no' id='n270' name='n270' href='#n270'>270</a>
<a class='no' id='n271' name='n271' href='#n271'>271</a>
<a class='no' id='n272' name='n272' href='#n272'>272</a>
<a class='no' id='n273' name='n273' href='#n273'>273</a>
<a class='no' id='n274' name='n274' href='#n274'>274</a>
<a class='no' id='n275' name='n275' href='#n275'>275</a>
<a class='no' id='n276' name='n276' href='#n276'>276</a>
<a class='no' id='n277' name='n277' href='#n277'>277</a>
<a class='no' id='n278' name='n278' href='#n278'>278</a>
<a class='no' id='n279' name='n279' href='#n279'>279</a>
<a class='no' id='n280' name='n280' href='#n280'>280</a>
<a class='no' id='n281' name='n281' href='#n281'>281</a>
<a class='no' id='n282' name='n282' href='#n282'>282</a>
<a class='no' id='n283' name='n283' href='#n283'>283</a>
<a class='no' id='n284' name='n284' href='#n284'>284</a>
<a class='no' id='n285' name='n285' href='#n285'>285</a>
<a class='no' id='n286' name='n286' href='#n286'>286</a>
<a class='no' id='n287' name='n287' href='#n287'>287</a>
<a class='no' id='n288' name='n288' href='#n288'>288</a>
<a class='no' id='n289' name='n289' href='#n289'>289</a>
<a class='no' id='n290' name='n290' href='#n290'>290</a>
<a class='no' id='n291' name='n291' href='#n291'>291</a>
<a class='no' id='n292' name='n292' href='#n292'>292</a>
<a class='no' id='n293' name='n293' href='#n293'>293</a>
<a class='no' id='n294' name='n294' href='#n294'>294</a>
<a class='no' id='n295' name='n295' href='#n295'>295</a>
<a class='no' id='n296' name='n296' href='#n296'>296</a>
<a class='no' id='n297' name='n297' href='#n297'>297</a>
<a class='no' id='n298' name='n298' href='#n298'>298</a>
<a class='no' id='n299' name='n299' href='#n299'>299</a>
<a class='no' id='n300' name='n300' href='#n300'>300</a>
<a class='no' id='n301' name='n301' href='#n301'>301</a>
<a class='no' id='n302' name='n302' href='#n302'>302</a>
<a class='no' id='n303' name='n303' href='#n303'>303</a>
<a class='no' id='n304' name='n304' href='#n304'>304</a>
<a class='no' id='n305' name='n305' href='#n305'>305</a>
<a class='no' id='n306' name='n306' href='#n306'>306</a>
<a class='no' id='n307' name='n307' href='#n307'>307</a>
<a class='no' id='n308' name='n308' href='#n308'>308</a>
<a class='no' id='n309' name='n309' href='#n309'>309</a>
<a class='no' id='n310' name='n310' href='#n310'>310</a>
<a class='no' id='n311' name='n311' href='#n311'>311</a>
<a class='no' id='n312' name='n312' href='#n312'>312</a>
<a class='no' id='n313' name='n313' href='#n313'>313</a>
<a class='no' id='n314' name='n314' href='#n314'>314</a>
<a class='no' id='n315' name='n315' href='#n315'>315</a>
<a class='no' id='n316' name='n316' href='#n316'>316</a>
<a class='no' id='n317' name='n317' href='#n317'>317</a>
<a class='no' id='n318' name='n318' href='#n318'>318</a>
<a class='no' id='n319' name='n319' href='#n319'>319</a>
<a class='no' id='n320' name='n320' href='#n320'>320</a>
<a class='no' id='n321' name='n321' href='#n321'>321</a>
<a class='no' id='n322' name='n322' href='#n322'>322</a>
<a class='no' id='n323' name='n323' href='#n323'>323</a>
<a class='no' id='n324' name='n324' href='#n324'>324</a>
<a class='no' id='n325' name='n325' href='#n325'>325</a>
<a class='no' id='n326' name='n326' href='#n326'>326</a>
<a class='no' id='n327' name='n327' href='#n327'>327</a>
<a class='no' id='n328' name='n328' href='#n328'>328</a>
<a class='no' id='n329' name='n329' href='#n329'>329</a>
<a class='no' id='n330' name='n330' href='#n330'>330</a>
<a class='no' id='n331' name='n331' href='#n331'>331</a>
<a class='no' id='n332' name='n332' href='#n332'>332</a>
<a class='no' id='n333' name='n333' href='#n333'>333</a>
<a class='no' id='n334' name='n334' href='#n334'>334</a>
<a class='no' id='n335' name='n335' href='#n335'>335</a>
<a class='no' id='n336' name='n336' href='#n336'>336</a>
<a class='no' id='n337' name='n337' href='#n337'>337</a>
<a class='no' id='n338' name='n338' href='#n338'>338</a>
<a class='no' id='n339' name='n339' href='#n339'>339</a>
<a class='no' id='n340' name='n340' href='#n340'>340</a>
<a class='no' id='n341' name='n341' href='#n341'>341</a>
<a class='no' id='n342' name='n342' href='#n342'>342</a>
<a class='no' id='n343' name='n343' href='#n343'>343</a>
<a class='no' id='n344' name='n344' href='#n344'>344</a>
<a class='no' id='n345' name='n345' href='#n345'>345</a>
<a class='no' id='n346' name='n346' href='#n346'>346</a>
<a class='no' id='n347' name='n347' href='#n347'>347</a>
<a class='no' id='n348' name='n348' href='#n348'>348</a>
<a class='no' id='n349' name='n349' href='#n349'>349</a>
<a class='no' id='n350' name='n350' href='#n350'>350</a>
<a class='no' id='n351' name='n351' href='#n351'>351</a>
<a class='no' id='n352' name='n352' href='#n352'>352</a>
<a class='no' id='n353' name='n353' href='#n353'>353</a>
<a class='no' id='n354' name='n354' href='#n354'>354</a>
<a class='no' id='n355' name='n355' href='#n355'>355</a>
<a class='no' id='n356' name='n356' href='#n356'>356</a>
<a class='no' id='n357' name='n357' href='#n357'>357</a>
<a class='no' id='n358' name='n358' href='#n358'>358</a>
<a class='no' id='n359' name='n359' href='#n359'>359</a>
<a class='no' id='n360' name='n360' href='#n360'>360</a>
<a class='no' id='n361' name='n361' href='#n361'>361</a>
<a class='no' id='n362' name='n362' href='#n362'>362</a>
<a class='no' id='n363' name='n363' href='#n363'>363</a>
<a class='no' id='n364' name='n364' href='#n364'>364</a>
<a class='no' id='n365' name='n365' href='#n365'>365</a>
<a class='no' id='n366' name='n366' href='#n366'>366</a>
<a class='no' id='n367' name='n367' href='#n367'>367</a>
<a class='no' id='n368' name='n368' href='#n368'>368</a>
<a class='no' id='n369' name='n369' href='#n369'>369</a>
<a class='no' id='n370' name='n370' href='#n370'>370</a>
<a class='no' id='n371' name='n371' href='#n371'>371</a>
<a class='no' id='n372' name='n372' href='#n372'>372</a>
<a class='no' id='n373' name='n373' href='#n373'>373</a>
<a class='no' id='n374' name='n374' href='#n374'>374</a>
<a class='no' id='n375' name='n375' href='#n375'>375</a>
<a class='no' id='n376' name='n376' href='#n376'>376</a>
<a class='no' id='n377' name='n377' href='#n377'>377</a>
<a class='no' id='n378' name='n378' href='#n378'>378</a>
<a class='no' id='n379' name='n379' href='#n379'>379</a>
<a class='no' id='n380' name='n380' href='#n380'>380</a>
<a class='no' id='n381' name='n381' href='#n381'>381</a>
<a class='no' id='n382' name='n382' href='#n382'>382</a>
<a class='no' id='n383' name='n383' href='#n383'>383</a>
<a class='no' id='n384' name='n384' href='#n384'>384</a>
<a class='no' id='n385' name='n385' href='#n385'>385</a>
<a class='no' id='n386' name='n386' href='#n386'>386</a>
<a class='no' id='n387' name='n387' href='#n387'>387</a>
<a class='no' id='n388' name='n388' href='#n388'>388</a>
<a class='no' id='n389' name='n389' href='#n389'>389</a>
<a class='no' id='n390' name='n390' href='#n390'>390</a>
<a class='no' id='n391' name='n391' href='#n391'>391</a>
<a class='no' id='n392' name='n392' href='#n392'>392</a>
<a class='no' id='n393' name='n393' href='#n393'>393</a>
<a class='no' id='n394' name='n394' href='#n394'>394</a>
<a class='no' id='n395' name='n395' href='#n395'>395</a>
<a class='no' id='n396' name='n396' href='#n396'>396</a>
<a class='no' id='n397' name='n397' href='#n397'>397</a>
<a class='no' id='n398' name='n398' href='#n398'>398</a>
<a class='no' id='n399' name='n399' href='#n399'>399</a>
<a class='no' id='n400' name='n400' href='#n400'>400</a>
<a class='no' id='n401' name='n401' href='#n401'>401</a>
<a class='no' id='n402' name='n402' href='#n402'>402</a>
<a class='no' id='n403' name='n403' href='#n403'>403</a>
<a class='no' id='n404' name='n404' href='#n404'>404</a>
<a class='no' id='n405' name='n405' href='#n405'>405</a>
<a class='no' id='n406' name='n406' href='#n406'>406</a>
<a class='no' id='n407' name='n407' href='#n407'>407</a>
<a class='no' id='n408' name='n408' href='#n408'>408</a>
<a class='no' id='n409' name='n409' href='#n409'>409</a>
<a class='no' id='n410' name='n410' href='#n410'>410</a>
<a class='no' id='n411' name='n411' href='#n411'>411</a>
<a class='no' id='n412' name='n412' href='#n412'>412</a>
<a class='no' id='n413' name='n413' href='#n413'>413</a>
<a class='no' id='n414' name='n414' href='#n414'>414</a>
<a class='no' id='n415' name='n415' href='#n415'>415</a>
<a class='no' id='n416' name='n416' href='#n416'>416</a>
<a class='no' id='n417' name='n417' href='#n417'>417</a>
<a class='no' id='n418' name='n418' href='#n418'>418</a>
<a class='no' id='n419' name='n419' href='#n419'>419</a>
<a class='no' id='n420' name='n420' href='#n420'>420</a>
<a class='no' id='n421' name='n421' href='#n421'>421</a>
<a class='no' id='n422' name='n422' href='#n422'>422</a>
<a class='no' id='n423' name='n423' href='#n423'>423</a>
<a class='no' id='n424' name='n424' href='#n424'>424</a>
<a class='no' id='n425' name='n425' href='#n425'>425</a>
<a class='no' id='n426' name='n426' href='#n426'>426</a>
<a class='no' id='n427' name='n427' href='#n427'>427</a>
<a class='no' id='n428' name='n428' href='#n428'>428</a>
<a class='no' id='n429' name='n429' href='#n429'>429</a>
<a class='no' id='n430' name='n430' href='#n430'>430</a>
<a class='no' id='n431' name='n431' href='#n431'>431</a>
<a class='no' id='n432' name='n432' href='#n432'>432</a>
<a class='no' id='n433' name='n433' href='#n433'>433</a>
<a class='no' id='n434' name='n434' href='#n434'>434</a>
<a class='no' id='n435' name='n435' href='#n435'>435</a>
<a class='no' id='n436' name='n436' href='#n436'>436</a>
<a class='no' id='n437' name='n437' href='#n437'>437</a>
<a class='no' id='n438' name='n438' href='#n438'>438</a>
<a class='no' id='n439' name='n439' href='#n439'>439</a>
<a class='no' id='n440' name='n440' href='#n440'>440</a>
<a class='no' id='n441' name='n441' href='#n441'>441</a>
<a class='no' id='n442' name='n442' href='#n442'>442</a>
<a class='no' id='n443' name='n443' href='#n443'>443</a>
<a class='no' id='n444' name='n444' href='#n444'>444</a>
<a class='no' id='n445' name='n445' href='#n445'>445</a>
<a class='no' id='n446' name='n446' href='#n446'>446</a>
<a class='no' id='n447' name='n447' href='#n447'>447</a>
<a class='no' id='n448' name='n448' href='#n448'>448</a>
<a class='no' id='n449' name='n449' href='#n449'>449</a>
<a class='no' id='n450' name='n450' href='#n450'>450</a>
<a class='no' id='n451' name='n451' href='#n451'>451</a>
<a class='no' id='n452' name='n452' href='#n452'>452</a>
<a class='no' id='n453' name='n453' href='#n453'>453</a>
<a class='no' id='n454' name='n454' href='#n454'>454</a>
<a class='no' id='n455' name='n455' href='#n455'>455</a>
<a class='no' id='n456' name='n456' href='#n456'>456</a>
<a class='no' id='n457' name='n457' href='#n457'>457</a>
<a class='no' id='n458' name='n458' href='#n458'>458</a>
<a class='no' id='n459' name='n459' href='#n459'>459</a>
<a class='no' id='n460' name='n460' href='#n460'>460</a>
<a class='no' id='n461' name='n461' href='#n461'>461</a>
<a class='no' id='n462' name='n462' href='#n462'>462</a>
<a class='no' id='n463' name='n463' href='#n463'>463</a>
<a class='no' id='n464' name='n464' href='#n464'>464</a>
<a class='no' id='n465' name='n465' href='#n465'>465</a>
<a class='no' id='n466' name='n466' href='#n466'>466</a>
<a class='no' id='n467' name='n467' href='#n467'>467</a>
<a class='no' id='n468' name='n468' href='#n468'>468</a>
<a class='no' id='n469' name='n469' href='#n469'>469</a>
<a class='no' id='n470' name='n470' href='#n470'>470</a>
<a class='no' id='n471' name='n471' href='#n471'>471</a>
<a class='no' id='n472' name='n472' href='#n472'>472</a>
<a class='no' id='n473' name='n473' href='#n473'>473</a>
<a class='no' id='n474' name='n474' href='#n474'>474</a>
<a class='no' id='n475' name='n475' href='#n475'>475</a>
<a class='no' id='n476' name='n476' href='#n476'>476</a>
<a class='no' id='n477' name='n477' href='#n477'>477</a>
<a class='no' id='n478' name='n478' href='#n478'>478</a>
<a class='no' id='n479' name='n479' href='#n479'>479</a>
<a class='no' id='n480' name='n480' href='#n480'>480</a>
<a class='no' id='n481' name='n481' href='#n481'>481</a>
<a class='no' id='n482' name='n482' href='#n482'>482</a>
<a class='no' id='n483' name='n483' href='#n483'>483</a>
<a class='no' id='n484' name='n484' href='#n484'>484</a>
<a class='no' id='n485' name='n485' href='#n485'>485</a>
<a class='no' id='n486' name='n486' href='#n486'>486</a>
<a class='no' id='n487' name='n487' href='#n487'>487</a>
<a class='no' id='n488' name='n488' href='#n488'>488</a>
<a class='no' id='n489' name='n489' href='#n489'>489</a>
<a class='no' id='n490' name='n490' href='#n490'>490</a>
<a class='no' id='n491' name='n491' href='#n491'>491</a>
<a class='no' id='n492' name='n492' href='#n492'>492</a>
<a class='no' id='n493' name='n493' href='#n493'>493</a>
<a class='no' id='n494' name='n494' href='#n494'>494</a>
<a class='no' id='n495' name='n495' href='#n495'>495</a>
<a class='no' id='n496' name='n496' href='#n496'>496</a>
<a class='no' id='n497' name='n497' href='#n497'>497</a>
<a class='no' id='n498' name='n498' href='#n498'>498</a>
<a class='no' id='n499' name='n499' href='#n499'>499</a>
<a class='no' id='n500' name='n500' href='#n500'>500</a>
<a class='no' id='n501' name='n501' href='#n501'>501</a>
<a class='no' id='n502' name='n502' href='#n502'>502</a>
<a class='no' id='n503' name='n503' href='#n503'>503</a>
<a class='no' id='n504' name='n504' href='#n504'>504</a>
<a class='no' id='n505' name='n505' href='#n505'>505</a>
<a class='no' id='n506' name='n506' href='#n506'>506</a>
<a class='no' id='n507' name='n507' href='#n507'>507</a>
<a class='no' id='n508' name='n508' href='#n508'>508</a>
<a class='no' id='n509' name='n509' href='#n509'>509</a>
<a class='no' id='n510' name='n510' href='#n510'>510</a>
<a class='no' id='n511' name='n511' href='#n511'>511</a>
<a class='no' id='n512' name='n512' href='#n512'>512</a>
<a class='no' id='n513' name='n513' href='#n513'>513</a>
</pre></td>
<td class='lines'><pre><code>/*
 * Mesa 3-D graphics library
 * 
 * Copyright (C) 1999-2006  Brian Paul   All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef GLX_H
#define GLX_H


#include &lt;X11/Xlib.h&gt;
#include &lt;X11/Xutil.h&gt;
#include &lt;GL/gl.h&gt;


#if defined(USE_MGL_NAMESPACE)
#include "glx_mangle.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


#define GLX_VERSION_1_1		1
#define GLX_VERSION_1_2		1
#define GLX_VERSION_1_3		1
#define GLX_VERSION_1_4		1

#define GLX_EXTENSION_NAME   "GLX"



/*
 * Tokens for glXChooseVisual and glXGetConfig:
 */
#define GLX_USE_GL		1
#define GLX_BUFFER_SIZE		2
#define GLX_LEVEL		3
#define GLX_RGBA		4
#define GLX_DOUBLEBUFFER	5
#define GLX_STEREO		6
#define GLX_AUX_BUFFERS		7
#define GLX_RED_SIZE		8
#define GLX_GREEN_SIZE		9
#define GLX_BLUE_SIZE		10
#define GLX_ALPHA_SIZE		11
#define GLX_DEPTH_SIZE		12
#define GLX_STENCIL_SIZE	13
#define GLX_ACCUM_RED_SIZE	14
#define GLX_ACCUM_GREEN_SIZE	15
#define GLX_ACCUM_BLUE_SIZE	16
#define GLX_ACCUM_ALPHA_SIZE	17


/*
 * Error codes returned by glXGetConfig:
 */
#define GLX_BAD_SCREEN		1
#define GLX_BAD_ATTRIBUTE	2
#define GLX_NO_EXTENSION	3
#define GLX_BAD_VISUAL		4
#define GLX_BAD_CONTEXT		5
#define GLX_BAD_VALUE       	6
#define GLX_BAD_ENUM		7


/*
 * GLX 1.1 and later:
 */
#define GLX_VENDOR		1
#define GLX_VERSION		2
#define GLX_EXTENSIONS 		3


/*
 * GLX 1.3 and later:
 */
#define GLX_CONFIG_CAVEAT		0x20
#define GLX_DONT_CARE			0xFFFFFFFF
#define GLX_X_VISUAL_TYPE		0x22
#define GLX_TRANSPARENT_TYPE		0x23
#define GLX_TRANSPARENT_INDEX_VALUE	0x24
#define GLX_TRANSPARENT_RED_VALUE	0x25
#define GLX_TRANSPARENT_GREEN_VALUE	0x26
#define GLX_TRANSPARENT_BLUE_VALUE	0x27
#define GLX_TRANSPARENT_ALPHA_VALUE	0x28
#define GLX_WINDOW_BIT			0x00000001
#define GLX_PIXMAP_BIT			0x00000002
#define GLX_PBUFFER_BIT			0x00000004
#define GLX_AUX_BUFFERS_BIT		0x00000010
#define GLX_FRONT_LEFT_BUFFER_BIT	0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT	0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT	0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT	0x00000008
#define GLX_DEPTH_BUFFER_BIT		0x00000020
#define GLX_STENCIL_BUFFER_BIT		0x00000040
#define GLX_ACCUM_BUFFER_BIT		0x00000080
#define GLX_NONE			0x8000
#define GLX_SLOW_CONFIG			0x8001
#define GLX_TRUE_COLOR			0x8002
#define GLX_DIRECT_COLOR		0x8003
#define GLX_PSEUDO_COLOR		0x8004
#define GLX_STATIC_COLOR		0x8005
#define GLX_GRAY_SCALE			0x8006
#define GLX_STATIC_GRAY			0x8007
#define GLX_TRANSPARENT_RGB		0x8008
#define GLX_TRANSPARENT_INDEX		0x8009
#define GLX_VISUAL_ID			0x800B
#define GLX_SCREEN			0x800C
#define GLX_NON_CONFORMANT_CONFIG	0x800D
#define GLX_DRAWABLE_TYPE		0x8010
#define GLX_RENDER_TYPE			0x8011
#define GLX_X_RENDERABLE		0x8012
#define GLX_FBCONFIG_ID			0x8013
#define GLX_RGBA_TYPE			0x8014
#define GLX_COLOR_INDEX_TYPE		0x8015
#define GLX_MAX_PBUFFER_WIDTH		0x8016
#define GLX_MAX_PBUFFER_HEIGHT		0x8017
#define GLX_MAX_PBUFFER_PIXELS		0x8018
#define GLX_PRESERVED_CONTENTS		0x801B
#define GLX_LARGEST_PBUFFER		0x801C
#define GLX_WIDTH			0x801D
#define GLX_HEIGHT			0x801E
#define GLX_EVENT_MASK			0x801F
#define GLX_DAMAGED			0x8020
#define GLX_SAVED			0x8021
#define GLX_WINDOW			0x8022
#define GLX_PBUFFER			0x8023
#define GLX_PBUFFER_HEIGHT              0x8040
#define GLX_PBUFFER_WIDTH               0x8041
#define GLX_RGBA_BIT			0x00000001
#define GLX_COLOR_INDEX_BIT		0x00000002
#define GLX_PBUFFER_CLOBBER_MASK	0x08000000


/*
 * GLX 1.4 and later:
 */
#define GLX_SAMPLE_BUFFERS              0x186a0 /*100000*/
#define GLX_SAMPLES                     0x186a1 /*100001*/



typedef struct __GLXcontextRec *GLXContext;
typedef XID GLXPixmap;
typedef XID GLXDrawable;
/* GLX 1.3 and later */
typedef struct __GLXFBConfigRec *GLXFBConfig;
typedef XID GLXFBConfigID;
typedef XID GLXContextID;
typedef XID GLXWindow;
typedef XID GLXPbuffer;


/*
** Events.
** __GLX_NUMBER_EVENTS is set to 17 to account for the BufferClobberSGIX
**  event - this helps initialization if the server supports the pbuffer
**  extension and the client doesn't.
*/
#define GLX_PbufferClobber	0
#define GLX_BufferSwapComplete	1

#define __GLX_NUMBER_EVENTS 17

extern XVisualInfo* glXChooseVisual( Display *dpy, int screen,
				     int *attribList );

extern GLXContext glXCreateContext( Display *dpy, XVisualInfo *vis,
				    GLXContext shareList, Bool direct );

extern void glXDestroyContext( Display *dpy, GLXContext ctx );

extern Bool glXMakeCurrent( Display *dpy, GLXDrawable drawable,
			    GLXContext ctx);

extern void glXCopyContext( Display *dpy, GLXContext src, GLXContext dst,
			    unsigned long mask );

extern void glXSwapBuffers( Display *dpy, GLXDrawable drawable );

extern GLXPixmap glXCreateGLXPixmap( Display *dpy, XVisualInfo *visual,
				     Pixmap pixmap );

extern void glXDestroyGLXPixmap( Display *dpy, GLXPixmap pixmap );

extern Bool glXQueryExtension( Display *dpy, int *errorb, int *event );

extern Bool glXQueryVersion( Display *dpy, int *maj, int *min );

extern Bool glXIsDirect( Display *dpy, GLXContext ctx );

extern int glXGetConfig( Display *dpy, XVisualInfo *visual,
			 int attrib, int *value );

extern GLXContext glXGetCurrentContext( void );

extern GLXDrawable glXGetCurrentDrawable( void );

extern void glXWaitGL( void );

extern void glXWaitX( void );

extern void glXUseXFont( Font font, int first, int count, int list );



/* GLX 1.1 and later */
extern const char *glXQueryExtensionsString( Display *dpy, int screen );

extern const char *glXQueryServerString( Display *dpy, int screen, int name );

extern const char *glXGetClientString( Display *dpy, int name );


/* GLX 1.2 and later */
extern Display *glXGetCurrentDisplay( void );


/* GLX 1.3 and later */
extern GLXFBConfig *glXChooseFBConfig( Display *dpy, int screen,
                                       const int *attribList, int *nitems );

extern int glXGetFBConfigAttrib( Display *dpy, GLXFBConfig config,
                                 int attribute, int *value );

extern GLXFBConfig *glXGetFBConfigs( Display *dpy, int screen,
                                     int *nelements );

extern XVisualInfo *glXGetVisualFromFBConfig( Display *dpy,
                                              GLXFBConfig config );

extern GLXWindow glXCreateWindow( Display *dpy, GLXFBConfig config,
                                  Window win, const int *attribList );

extern void glXDestroyWindow( Display *dpy, GLXWindow window );

extern GLXPixmap glXCreatePixmap( Display *dpy, GLXFBConfig config,
                                  Pixmap pixmap, const int *attribList );

extern void glXDestroyPixmap( Display *dpy, GLXPixmap pixmap );

extern GLXPbuffer glXCreatePbuffer( Display *dpy, GLXFBConfig config,
                                    const int *attribList );

extern void glXDestroyPbuffer( Display *dpy, GLXPbuffer pbuf );

extern void glXQueryDrawable( Display *dpy, GLXDrawable draw, int attribute,
                              unsigned int *value );

extern GLXContext glXCreateNewContext( Display *dpy, GLXFBConfig config,
                                       int renderType, GLXContext shareList,
                                       Bool direct );

extern Bool glXMakeContextCurrent( Display *dpy, GLXDrawable draw,
                                   GLXDrawable read, GLXContext ctx );

extern GLXDrawable glXGetCurrentReadDrawable( void );

extern int glXQueryContext( Display *dpy, GLXContext ctx, int attribute,
                            int *value );

extern void glXSelectEvent( Display *dpy, GLXDrawable drawable,
                            unsigned long mask );

extern void glXGetSelectedEvent( Display *dpy, GLXDrawable drawable,
                                 unsigned long *mask );

/* GLX 1.3 function pointer typedefs */
typedef GLXFBConfig * (* PFNGLXGETFBCONFIGSPROC) (Display *dpy, int screen, int *nelements);
typedef GLXFBConfig * (* PFNGLXCHOOSEFBCONFIGPROC) (Display *dpy, int screen, const int *attrib_list, int *nelements);
typedef int (* PFNGLXGETFBCONFIGATTRIBPROC) (Display *dpy, GLXFBConfig config, int attribute, int *value);
typedef XVisualInfo * (* PFNGLXGETVISUALFROMFBCONFIGPROC) (Display *dpy, GLXFBConfig config);
typedef GLXWindow (* PFNGLXCREATEWINDOWPROC) (Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
typedef void (* PFNGLXDESTROYWINDOWPROC) (Display *dpy, GLXWindow win);
typedef GLXPixmap (* PFNGLXCREATEPIXMAPPROC) (Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
typedef void (* PFNGLXDESTROYPIXMAPPROC) (Display *dpy, GLXPixmap pixmap);
typedef GLXPbuffer (* PFNGLXCREATEPBUFFERPROC) (Display *dpy, GLXFBConfig config, const int *attrib_list);
typedef void (* PFNGLXDESTROYPBUFFERPROC) (Display *dpy, GLXPbuffer pbuf);
typedef void (* PFNGLXQUERYDRAWABLEPROC) (Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
typedef GLXContext (* PFNGLXCREATENEWCONTEXTPROC) (Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef Bool (* PFNGLXMAKECONTEXTCURRENTPROC) (Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable (* PFNGLXGETCURRENTREADDRAWABLEPROC) (void);
typedef Display * (* PFNGLXGETCURRENTDISPLAYPROC) (void);
typedef int (* PFNGLXQUERYCONTEXTPROC) (Display *dpy, GLXContext ctx, int attribute, int *value);
typedef void (* PFNGLXSELECTEVENTPROC) (Display *dpy, GLXDrawable draw, unsigned long event_mask);
typedef void (* PFNGLXGETSELECTEDEVENTPROC) (Display *dpy, GLXDrawable draw, unsigned long *event_mask);


/*
 * ARB 2. GLX_ARB_get_proc_address
 */
#ifndef GLX_ARB_get_proc_address
#define GLX_ARB_get_proc_address 1

typedef void (*__GLXextFuncPtr)(void);
extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);

#endif /* GLX_ARB_get_proc_address */



/* GLX 1.4 and later */
extern void (*glXGetProcAddress(const GLubyte *procname))( void );

/* GLX 1.4 function pointer typedefs */
typedef __GLXextFuncPtr (* PFNGLXGETPROCADDRESSPROC) (const GLubyte *procName);


#ifndef GLX_GLXEXT_LEGACY

#include &lt;GL/glxext.h&gt;

#endif /* GLX_GLXEXT_LEGACY */


/**
 ** The following aren't in glxext.h yet.
 **/


/*
 * ???. GLX_NV_vertex_array_range
 */
#ifndef GLX_NV_vertex_array_range
#define GLX_NV_vertex_array_range

extern void *glXAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
extern void glXFreeMemoryNV(GLvoid *pointer);
typedef void * ( * PFNGLXALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
typedef void ( * PFNGLXFREEMEMORYNVPROC) (GLvoid *pointer);

#endif /* GLX_NV_vertex_array_range */


/*
 * ARB ?. GLX_ARB_render_texture
 * XXX This was never finalized!
 */
#ifndef GLX_ARB_render_texture
#define GLX_ARB_render_texture 1

extern Bool glXBindTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer);
extern Bool glXReleaseTexImageARB(Display *dpy, GLXPbuffer pbuffer, int buffer);
extern Bool glXDrawableAttribARB(Display *dpy, GLXDrawable draw, const int *attribList);

#endif /* GLX_ARB_render_texture */


/*
 * Remove this when glxext.h is updated.
 */
#ifndef GLX_NV_float_buffer
#define GLX_NV_float_buffer 1

#define GLX_FLOAT_COMPONENTS_NV         0x20B0

#endif /* GLX_NV_float_buffer */



/*
 * #?. GLX_MESA_swap_frame_usage
 */
#ifndef GLX_MESA_swap_frame_usage
#define GLX_MESA_swap_frame_usage 1

extern int glXGetFrameUsageMESA(Display *dpy, GLXDrawable drawable, float *usage);
extern int glXBeginFrameTrackingMESA(Display *dpy, GLXDrawable drawable);
extern int glXEndFrameTrackingMESA(Display *dpy, GLXDrawable drawable);
extern int glXQueryFrameTrackingMESA(Display *dpy, GLXDrawable drawable, int64_t *swapCount, int64_t *missedFrames, float *lastMissedUsage);

typedef int (*PFNGLXGETFRAMEUSAGEMESAPROC) (Display *dpy, GLXDrawable drawable, float *usage);
typedef int (*PFNGLXBEGINFRAMETRACKINGMESAPROC)(Display *dpy, GLXDrawable drawable);
typedef int (*PFNGLXENDFRAMETRACKINGMESAPROC)(Display *dpy, GLXDrawable drawable);
typedef int (*PFNGLXQUERYFRAMETRACKINGMESAPROC)(Display *dpy, GLXDrawable drawable, int64_t *swapCount, int64_t *missedFrames, float *lastMissedUsage);

#endif /* GLX_MESA_swap_frame_usage */



/*
 * #?. GLX_MESA_swap_control
 */
#ifndef GLX_MESA_swap_control
#define GLX_MESA_swap_control 1

extern int glXSwapIntervalMESA(unsigned int interval);
extern int glXGetSwapIntervalMESA(void);

typedef int (*PFNGLXSWAPINTERVALMESAPROC)(unsigned int interval);
typedef int (*PFNGLXGETSWAPINTERVALMESAPROC)(void);

#endif /* GLX_MESA_swap_control */



/*
 * #?. GLX_EXT_texture_from_pixmap
 * XXX not finished?
 */
#ifndef GLX_EXT_texture_from_pixmap
#define GLX_EXT_texture_from_pixmap 1

#define GLX_BIND_TO_TEXTURE_RGB_EXT        0x20D0
#define GLX_BIND_TO_TEXTURE_RGBA_EXT       0x20D1
#define GLX_BIND_TO_MIPMAP_TEXTURE_EXT     0x20D2
#define GLX_BIND_TO_TEXTURE_TARGETS_EXT    0x20D3
#define GLX_Y_INVERTED_EXT                 0x20D4

#define GLX_TEXTURE_FORMAT_EXT             0x20D5
#define GLX_TEXTURE_TARGET_EXT             0x20D6
#define GLX_MIPMAP_TEXTURE_EXT             0x20D7

#define GLX_TEXTURE_FORMAT_NONE_EXT        0x20D8
#define GLX_TEXTURE_FORMAT_RGB_EXT         0x20D9
#define GLX_TEXTURE_FORMAT_RGBA_EXT        0x20DA

#define GLX_TEXTURE_1D_BIT_EXT             0x00000001
#define GLX_TEXTURE_2D_BIT_EXT             0x00000002
#define GLX_TEXTURE_RECTANGLE_BIT_EXT      0x00000004

#define GLX_TEXTURE_1D_EXT                 0x20DB
#define GLX_TEXTURE_2D_EXT                 0x20DC
#define GLX_TEXTURE_RECTANGLE_EXT          0x20DD

#define GLX_FRONT_LEFT_EXT                 0x20DE
#define GLX_FRONT_RIGHT_EXT                0x20DF
#define GLX_BACK_LEFT_EXT                  0x20E0
#define GLX_BACK_RIGHT_EXT                 0x20E1
#define GLX_FRONT_EXT                      GLX_FRONT_LEFT_EXT
#define GLX_BACK_EXT                       GLX_BACK_LEFT_EXT
#define GLX_AUX0_EXT                       0x20E2
#define GLX_AUX1_EXT                       0x20E3 
#define GLX_AUX2_EXT                       0x20E4 
#define GLX_AUX3_EXT                       0x20E5 
#define GLX_AUX4_EXT                       0x20E6 
#define GLX_AUX5_EXT                       0x20E7 
#define GLX_AUX6_EXT                       0x20E8
#define GLX_AUX7_EXT                       0x20E9 
#define GLX_AUX8_EXT                       0x20EA 
#define GLX_AUX9_EXT                       0x20EB

extern void glXBindTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer, const int *attrib_list);
extern void glXReleaseTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer);

#endif /* GLX_EXT_texture_from_pixmap */




/*** Should these go here, or in another header? */
/*
** GLX Events
*/
typedef struct {
    int event_type;		/* GLX_DAMAGED or GLX_SAVED */
    int draw_type;		/* GLX_WINDOW or GLX_PBUFFER */
    unsigned long serial;	/* # of last request processed by server */
    Bool send_event;		/* true if this came for SendEvent request */
    Display *display;		/* display the event was read from */
    GLXDrawable drawable;	/* XID of Drawable */
    unsigned int buffer_mask;	/* mask indicating which buffers are affected */
    unsigned int aux_buffer;	/* which aux buffer was affected */
    int x, y;
    int width, height;
    int count;			/* if nonzero, at least this many more */
} GLXPbufferClobberEvent;

typedef struct {
    int type;
    unsigned long serial;	/* # of last request processed by server */
    Bool send_event;		/* true if this came from a SendEvent request */
    Display *display;		/* Display the event was read from */
    GLXDrawable drawable;	/* drawable on which event was requested in event mask */
    int event_type;
    int64_t ust;
    int64_t msc;
    int64_t sbc;
} GLXBufferSwapComplete;

typedef union __GLXEvent {
    GLXPbufferClobberEvent glxpbufferclobber;
    GLXBufferSwapComplete glxbufferswapcomplete;
    long pad[24];
} GLXEvent;

#ifdef __cplusplus
}
#endif

#endif
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated  by cgit v0.9.0.2-2-gbebe at 2013-07-30 08:31:35 (GMT)</div>
</div> <!-- id=cgit -->
</body>
</html>
