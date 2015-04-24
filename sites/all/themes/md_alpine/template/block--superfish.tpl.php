<?php
global $base_url;
    if(theme_get_setting('logo_retina_path')) {
    $logo_path = md_alpine_theme_setting_check_path(theme_get_setting('logo_retina_path'));
    } elseif(theme_get_setting('logo_normal_path')) {
    $logo_path = md_alpine_theme_setting_check_path(theme_get_setting('logo_normal_path'));
    } else {
    $logo_path = $base_url.'/'.drupal_get_path('theme','md_alpine').'/img/logo.png';
    }
?>
<div id="navigation" class="navbar navbar-default navbar-fixed-top" role="navigation">
    <div class="navbar-inner">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                <span class="sr-only">Toggle navigation</span>
                <i class="icon fontello icon-menu icon-2x"></i>
            </button>
            <a id="brand" class="navbar-brand" href="<?php print $base_url;?>"> <img src="<?php print $logo_path;?>" alt=""> </a>
        </div>
        <div class="navbar-collapse collapse">
            <?php print $content;?>
        </div>
    </div>
</div>