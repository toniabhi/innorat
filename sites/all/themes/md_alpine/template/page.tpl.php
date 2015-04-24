<?php $sidebar = theme_get_setting('sidebar_posotion') ?  theme_get_setting('sidebar_posotion') : 'right';?>
<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>
<section class="section-content blog-content">
<!-- Section title -->
<div class="section-title text-center">
     <div>
            <span class="line big"></span>
            <span>~</span>
            <span class="line big"></span>
     </div>
            <h1><?php print drupal_get_title();?></h1>
     <div>
            <span class="line"></span>
            <span>~</span>
            <span class="line"></span>
     </div>
        
</div>
    <!-- Section title -->
    <!-- <div class="section-title text-center">
        <h1><?php // drupal_get_title();?></h1>
    </div> -->
    <!-- Section title -->
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <?php print $messages; ?>
                <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
            </div>
            <?php if($sidebar && $sidebar == 'right' && !empty($page['sidebar'])):?>
                <?php if($page['content']):?>
                <div class="col-md-9">
                    <?php print render($page['content']);?>
                </div>
                <?php endif;?>
                <?php if($page['sidebar']):?>
                <div class="sidebar col-md-3 .col-md-push-9">
                    <?php print render($page['sidebar']);?>
                </div>
                <?php endif;?>
            <?php endif;?>
            <?php if($sidebar && $sidebar == 'left' && !empty($page['sidebar'])):?>
                <?php if($page['sidebar']):?>
                    <div class="sidebar col-md-3 .col-md-push-9">
                        <?php print render($page['sidebar']);?>
                    </div>
                <?php endif;?>
                <?php if($page['content']):?>
                    <div class="col-md-9">
                        <?php print render($page['content']);?>
                    </div>
                <?php endif;?>
            <?php endif;?>
            <?php if($sidebar && empty($page['sidebar'])):?>
                <?php if($page['content']):?>
                    <div class="col-md-12">
                        <?php print render($page['content']);?>
                    </div>
                <?php endif;?>
            <?php endif;?>
        </div>
    </div>
</section>
<?php if($page['footer']):?>
    <?php print render($page['footer']);?>
<?php endif;?>
<!-- Back to top -->
<a href="#" id="back-top"><i class="fontello icon-angle-up icon-2x"></i></a>
