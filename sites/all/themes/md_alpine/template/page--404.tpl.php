<?php global $base_url;?>
<!-- Intro loader -->
<div class="mask">
    <div id="intro-loader"></div>
</div>
<!-- Intro loader -->

<!-- Home Section -->
<section id="home" class="intro-pattern nf-pattern">
    <div class="text-home">
        <div class="intro-item">
            <div class="section-title text-center">
                <h1><?php print theme_get_setting('nf_text');?></h1>
                <p class="lead">
                    <?php print theme_get_setting('nf_des');?>
                </p>
            </div>
            <div class="mybutton ultra">
                <a class="start-button" href="<?php print $base_url;?>"> <span data-hover="Back to home"><?php print t('Back to home');?></span> </a>
            </div>
        </div>
    </div>
</section>
<!-- Home Section -->