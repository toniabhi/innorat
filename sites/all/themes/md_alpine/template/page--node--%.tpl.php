
<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>
<section class="section-content blog-content">
    <div class="container">
        <!-- Section title -->
        <?php if(isset($node)):?>
        <div class="section-title text-center">
            <div>
                <span class="line big"></span>
                <span>~</span>
                <span class="line big"></span>
            </div>
            <h1><?php print $node->title;?></h1>
            <div>
                <span class="line"></span>
                <span>~</span>
                <span class="line"></span>
            </div>
            <p class="lead">
                <?php if(isset($node->field_bl_description)):?>
                    <?php print $node->field_bl_description[$node->language][0]['value'];?>
                <?php endif;?>
            </p>
        </div>
        <?php endif; ?>
        <!-- Section title -->
        <div class="row">
            <div class="col-md-12">
                <?php print $messages; ?>
                <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
            </div>
            <?php if(theme_get_setting('sidebar_position') == 'right'):?>
                <?php if($page['content']):?>
                    <div class="col-md-12">
                        <?php print render($page['content']);?>
                    </div>
                <?php endif;?>
                <?php if($page['sidebar'] && isset($node) && $node->type != 'portfolio'):?>
                    <div class="sidebar col-md-3">
                        <?php print render($page['sidebar']);?>
                    </div>
                <?php endif;?>
            <?php endif;?>
            <?php if(theme_get_setting('sidebar_position') == 'left'):?>
                <?php if($page['sidebar'] && isset($node) && $node->type != 'portfolio'):?>
                    <div class="sidebar col-md-3">
                        <?php print render($page['sidebar']);?>
                    </div>
                <?php endif;?>
                <?php if($page['content']):?>
                    <div class="col-md-9">
                        <?php print render($page['content']);?>
                    </div>
                <?php endif;?>
            <?php endif;?>
            <?php if(theme_get_setting('sidebar_position') == 'no'):?>
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
