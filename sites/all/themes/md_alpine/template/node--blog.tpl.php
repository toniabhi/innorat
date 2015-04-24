
<?php
global $base_url;
if(isset($content['field_bl_multimedia'])) {
    $multimedia = $content['field_bl_multimedia']['#items'];
    $media_content = '';
    foreach($multimedia as $key => $value){
        $file_type = $value['file']->type;
        $file_uri = $value['file']->uri;
        if($file_type == 'image') {
            $media_content .= '<li><img src="'.image_style_url('blog_multimedia',$file_uri).'"/></li>';
        } else {
            $media_content .= '<li>'.render($content['field_bl_multimedia'][$key]).'</li>';
        }
    }
}
?>
<?php ?>

<div class="element-line">
    <div class="flexslider">
        <ul class="slides">
            <?php if(isset($media_content) && $media_content != null): print $media_content; endif;?>
        </ul>
    </div>
    <div class="blog-text">
        <?php print render($content['body']);?>
    </div>
    <?php print render($content['comments']); ?>
</div>