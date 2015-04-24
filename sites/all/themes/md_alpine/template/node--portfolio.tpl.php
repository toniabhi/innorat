<?php
$current_path = current_path();
if(isset($node->field_multimedia[$node->language])) {
    $multimedia = $node->field_multimedia[$node->language];
    $icon_type = '';
    $portfolio_media = '';
    foreach($multimedia as $key => $value) {
        if($value['file']->type == 'image') {
            if($node->field_po_layout_mode[$node->language][0]['value'] == '1') {
                $portfolio_media .= '<li><img class="img-responsive img-center img-rounded" src="'.image_style_url('portfolio_layout_1',$value['file']->uri).'"></li>';
            } else {
                $portfolio_media .= '<li><img class="img-responsive img-center img-rounded" src="'.image_style_url('portfolio_layout_2',$value['file']->uri).'"></li>';
            }
        } else {
            $portfolio_media .= '<li>'.render($content['field_multimedia'][$key]).'</li>';
        }

    }
}
if(isset($node->field_po_taxonomy[$node->language])) {
    $taxonomy = $node->field_po_taxonomy[$node->language];
    $taxonomy_output = '';
    foreach ($taxonomy as $key => $value){
        $taxonomy_output .= '<a href="'.base_url().'/taxonomy/term/'.$value['tid'].'">'.$value['taxonomy_term']->name.'</a> ';
    }
}
if(isset($node->field_po_layout_mode)) {
    if(empty($node->field_po_layout_mode[$node->language])) {
        $layout_mode = '1';
    } else {
        $layout_mode = $node->field_po_layout_mode[$node->language][0]['value'];
}
} else {
    $layout_mode = '1';
}
?>
<div id="ajaxpage">

    <div class="container">
        <div class="row">
            <div class="col-md-10 col-md-offset-1">
                <div class="section-title text-center">
                    <div>
                        <span class="line big"></span>
                        <span><?php print t('Posted by ');?><a href="<?php print url('/user/'.$node->uid);?>"><?php print $node->name;?></a></span>
                        <span class="line big"></span>
                    </div>
                    <h1><?php print $node->title;?></h1>
                    <div>
                        <span class="line"></span>
                        <span><i class="fontello icon-calendar"></i><?php print date('d F Y',$node->created);?></span>
                        <span class="line"></span>
                    </div>
                </div>

                <?php if(isset($layout_mode) && $layout_mode == '1') : ?>
                    <div class="project-media">
                        <div class="row">
                            <div class="col-md-12">
                                <div class="flexslider">
                                    <ul class="slides">
                                        <?php if(isset($portfolio_media)): print $portfolio_media; endif;?>
                                    </ul>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="project-description">
                        <div class="row">
                            <div class="col-md-12">
                                <div class="text-center">
                                    <div class="project-details">
                                        <h4><?php print t('Project Description');?></h4>
                                        <p>
                                           <?php print render($content['field_po_description']);?>
                                        </p>
                                    </div>
                                    <div class="project-details">

                                        <div class="row">
                                            <div class="col-md-4">
                                                <p class="list-info">
                                                    <i class="fontello icon-briefcase fa-lg"></i>
                                                    <span><?php print render($content['field_po_author_name']);?></span>
                                                    <em><?php print render($content['field_po_author_company']);?></em>
                                                </p>
                                            </div>
                                            <div class="col-md-4">
                                                <p class="list-info">
                                                    <i class="fontello icon-calendar fa-lg"></i>
                                                    <span><?php print t('Publish on');?></span>
                                                    <em><?php print date('d F, Y',$node->created);?></em>
                                                </p>
                                            </div>
                                            <div class="col-md-4">
                                                <p class="list-info">
                                                    <i class="fontello icon-tags fa-lg"></i>
                                                    <span><?php print t('Tags');?></</span>
                                                    <em><?php if(isset($taxonomy_output)): print $taxonomy_output; endif;?></em>
                                                </p>
                                            </div>
                                        </div>
                                    </div>
                                    <?php if(isset($content['field_po_button_text']) && isset($content['field_po_button_link'])):?>
                                        <div class="mybutton medium">
                                            <a href="<?php print render($content['field_po_button_link']);?>"><span data-hover="<?php print ($node->field_po_button_text[$node->language][0]['value']);?>"><?php print ($node->field_po_button_text[$node->language][0]['value']);?></span></a>
                                        </div>
                                    <?php endif;?>
                                </div>
                            </div>
                        </div>
                    </div>
                <?php elseif($layout_mode == '2') :?>
                    <div class="col-md-8 col-sm-12">
                        <div class="project-media">
                            <div class="row">
                                <div class="col-md-12">
                                    <div class="flexslider img-rounded">
                                        <ul class="slides">
                                            <?php print $portfolio_media;?>
                                        </ul>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="col-md-4 col-sm-12">

                        <div class="project-description">

                            <div class="project-details">
                                <h4><?php print t('Project Description');?></h4>
                                <p>
                                    <?php print render($content['field_po_description']);?>
                                </p>
                            </div>

                            <div class="project-details">
                                <p class="list-info">
                                    <i class="fontello icon-briefcase fa-lg"></i>
                                    <span><?php print render($content['field_po_author_name']);?></span>
                                    <em><?php print render($content['field_po_author_company']);?></em>
                                </p>
                                <p class="list-info">
                                    <i class="fontello icon-calendar fa-lg"></i>
                                    <span><?php print t('Publish on');?></span>
                                    <em><?php print date('d F, Y',$node->created);?></em>
                                </p>
                                <p class="list-info">
                                    <i class="fontello icon-tags fa-lg"></i>
                                    <span><?php print t('Tags');?></</span>
                                    <em><?php if(isset($taxonomy_output)) : print $taxonomy_output; endif ;?></em>
                                </p>
                            </div>
                            <?php if(isset($content['field_po_button_text']) && isset($content['field_po_button_link'])):?>
                                <div class="mybutton medium">
                                    <a href="<?php print render($content['field_po_button_link']);?>"><span data-hover="<?php print ($node->field_po_button_text[$node->language][0]['value']);?>"><?php print ($node->field_po_button_text[$node->language][0]['value']);?></span></a>
                                </div>
                            <?php endif;?>
                        </div>
                    </div>
                <?php endif;?>
            </div>

        </div><!-- END ROW -->
    </div><!-- END CONTAINER -->
</div><!-- END AJAX PAGE -->